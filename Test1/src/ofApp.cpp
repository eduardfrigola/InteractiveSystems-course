#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    buttonWidth=200;
    buttonHeight=100;
    
    buttonPosition.x=ofGetWidth()/2-buttonWidth/2;
    buttonPosition.y=ofGetHeight()/2-buttonHeight/2;
    
    buttonColor.r=0;
    buttonColor.g=0;
    buttonColor.b=0;
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255, 255, 255);
    ofRect(100, 100, 100, 100);
    
    ofSetColor(255, 200, 15);
    ofCircle(ofPoint(250,50), 25);
    
    ofSetColor(255, 0, 0);
    ofBeginShape();
        ofVertex(100, 100);
        ofVertex(150, 50);
        ofVertex(200, 100);
    ofEndShape();
    
    ofSetColor(0);
    ofRect(0, 200, 300, 10);
    
    ofDrawBitmapString("3.14casso", ofPoint(5, 10));
    ofDrawBitmapString("Mouse Position: "+ofToString(mousePosition.x)+"x"+ofToString(mousePosition.y)+"y", ofPoint(5,20));
    
    ofPushStyle();
    ofSetColor(buttonColor);
    ofRect(buttonPosition.x, buttonPosition.y, buttonWidth, buttonHeight);
    ofPopStyle();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    ofBackground(rand()*255, rand()*255,rand()*255);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    mousePosition.x=x;
    mousePosition.y=y;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if(ofInRange(mousePosition.x, buttonPosition.x, buttonPosition.y+buttonWidth)&&ofInRange(mousePosition.y, buttonPosition.y, buttonPosition.x+buttonHeight)){
        buttonColor=ofColor(0,255,0);
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
