#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    image.load("images/sunflower.jpg");
    
    swapIn.allocate(ofGetWidth(), ofGetHeight());
    swapOut.allocate(ofGetWidth(), ofGetHeight());

    
    effect.loadShader("shaders/pixelation.vert", "shaders/pixelation.frag");
    effect.setupGui("Pixelation", "settings/pixelation.xml");
    effect.addUniformFloat("pixel_w", "Pixel Width", 1.0, 1.0, 50.0);
    effect.addUniformFloat("pixel_h", "Pixel Height", 1.0, 1.0, 50.0);

}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    swapIn.begin();
        image.draw(0, 0);
    swapIn.end();
    
    effect.apply(&swapIn, &swapOut);
    effect.apply(&swapOut, &swapIn);
    
    swapIn.draw(0, 0);
    effect.drawGui();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
