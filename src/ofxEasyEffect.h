//
//  ofxEasyEffect.h
//
//  Created by James Bentley on 13/05/16.
//
//

#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofxEasyEffect {
    ofShader shader;
    ofParameter<bool> active;
    ofParameterGroup uniformsGroup;
    int controllerNumber;
        
public:
    ofxEasyEffect();
    void setSharedUniforms(ofTexture inputTex, int screenWidth, int screenHeight);
    
    map< string, ofParameter<float>* > uniformFloats;
    map< string, ofTexture* > uniformTextures;
    map< string, ofImage* > uniformImages;
    map< string, pair< float*, int > > uniformArrays;
    map<string, ofParameter<bool>* > uniformBools;
        
    ofxPanel gui;
    
    void addUniformTexture(string name, ofTexture* texture);
    void addUniformImage(string name, ofImage* img);
    void addUniformFloat(string name, string parameterName, float initialValue, float minValue, float maxValue);
    void addUniformBool(string name, string parameterName, bool initialValue);
    void addUniformArray(string name, float* _vectorArray, int _size);

    ofParameter<bool> * getActiveParameter() { return &active; };
    
    void setActiveParameter(bool _param) { active.set(_param); };
    
    void setGuiPosition(int x, int y);
    
    float getGuiWidth();
    
    void setupGui(string name, string path);
    
    bool loadShader(string vertPath, string fragPath);

    void apply(ofFbo* fboIn, ofFbo* fboOut);
    void apply(ofFbo* fboIn, ofFbo* fboOut, ofMesh* mesh);
        
    void beginShader();
    void setUniqueUniforms();
    void endShader();
    ofShader* getShaderRef();
    ofParameterGroup* getParametersRef();
    void drawGui();
};