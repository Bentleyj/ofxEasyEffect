//
//  ofxEasyEffect.cpp
//
//  Created by James Bentley on 13/05/16.
//
//

#include "ofxEasyEffect.h"

ofxEasyEffect::ofxEasyEffect() {
}

void ofxEasyEffect::addUniformImage(string name, ofImage *img) {
    uniformImages[name] = img;
}

void ofxEasyEffect::addUniformTexture(string name, ofTexture* texture) {
    uniformTextures[name] = texture;
}

void ofxEasyEffect::setGuiPosition(int x, int y) {
    gui.setPosition(x, y);
}

void ofxEasyEffect::setupGui(string name, string path) {
    gui.setup(name, path);
    active.set(name, false);
}

bool ofxEasyEffect::loadShader(string vertPath, string fragPath) {
    return shader.load(vertPath, fragPath);
}

void ofxEasyEffect::addUniformFloat(string name, string parameterName, float initialValue, float minValue, float maxValue){
    uniformFloats[name] = new ofParameter<float>();
    uniformFloats[name]->set(parameterName, initialValue, minValue, maxValue);
    gui.add(*uniformFloats[name]);
}

void ofxEasyEffect::addUniformBool(string name, string parameterName, bool initialValue) {
    uniformBools[name] = new ofParameter<bool>();
    uniformBools[name]->set(parameterName, initialValue);
    gui.add(*uniformBools[name]);
}

void ofxEasyEffect::addUniformArray(string name, float* _vectorArray, int _size) {
    uniformArrays[name] = make_pair(_vectorArray, _size);
    
//    uniformVectorArrayNames.push_back(name);
//    uniformVectorArrays.push_back(_vectorArray);
//    uniformVectorArraySizes.push_back(_size);
}

void ofxEasyEffect::beginShader() {
    shader.begin();
}
    
void ofxEasyEffect::setSharedUniforms(ofTexture inputTex, int screenWidth, int screenHeight) {
    shader.setUniformTexture( "inputTexture", inputTex, 0 );
    shader.setUniform2f( "inputTextureSize", inputTex.getWidth(), inputTex.getHeight() );
    shader.setUniform1f( "time", ofGetElapsedTimef() );
    shader.setUniform2f( "size", (float)screenWidth, (float)screenHeight);
}

void ofxEasyEffect::setUniqueUniforms() {
    
    for( auto it = uniformFloats.begin(); it != uniformFloats.end(); it++) {
        shader.setUniform1f(it->first, it->second->get());
    }
    
    int texNum = 1;
    for( auto it = uniformImages.begin(); it != uniformImages.end(); it++) {
        shader.setUniformTexture(it->first, *it->second, texNum);
        shader.setUniform2f(it->first + "Size", it->second->getWidth(), it->second->getHeight());
        texNum++;
    }
    
    for( auto it = uniformTextures.begin(); it != uniformTextures.end(); it++) {
        shader.setUniformTexture(it->first, *it->second, texNum);
        shader.setUniform2f(it->first + "Size", it->second->getWidth(), it->second->getHeight());
        texNum++;
    }
    
    for(auto it = uniformArrays.begin(); it != uniformArrays.end(); it++) {
        shader.setUniform2fv(it->first, it->second.first, it->second.second);
        shader.setUniform1f(it->first + "Size", it->second.second);
    }
}

void ofxEasyEffect::endShader() {
    shader.end();
}

ofShader* ofxEasyEffect::getShaderRef() {
    return &shader;
}

void ofxEasyEffect::drawGui() {
    gui.draw();
}

float ofxEasyEffect::getGuiWidth() {
    return gui.getWidth();
}


ofParameterGroup* ofxEasyEffect::getParametersRef() {
    return &uniformsGroup;
}

void ofxEasyEffect::apply(ofFbo* fboIn, ofFbo* fboOut, ofMesh* mesh) {
    fboOut->begin();
    ofClear(0);
    shader.begin();
    setSharedUniforms(fboIn->getTexture(), ofGetWidth(), ofGetHeight());
    setUniqueUniforms();
    mesh->draw();
    shader.end();
    fboOut->end();
}

void ofxEasyEffect::apply(ofFbo* fboIn, ofFbo* fboOut) {
    fboOut->begin();
    ofClear(0);
    shader.begin();
    setSharedUniforms(fboIn->getTexture(), ofGetWidth(), ofGetHeight());
    setUniqueUniforms();
    fboIn->draw(0, 0);
    shader.end();
    fboOut->end();
}