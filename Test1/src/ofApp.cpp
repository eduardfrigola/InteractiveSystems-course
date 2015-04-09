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
    
    bikerOrigin=ofPoint(ofGetWidth()/2, ofGetHeight()/2);
    kneeLPosition=ofPoint(bikerOrigin.x+70,bikerOrigin.y);
    kneeRPosition=ofPoint(bikerOrigin.x+80,bikerOrigin.y);
    
    pedalierCenter=ofPoint(bikerOrigin.x+67, bikerOrigin.y+92);
    
    pedalLPosition=ofPoint(bikerOrigin.x+101, bikerOrigin.y+92);
    pedalRPosition=ofPoint(bikerOrigin.x+101, bikerOrigin.y+92);
    
    pedalRadius=34;
    
    zerotopi=0;
    
    bike.loadImage("bike_no_pedals.png");
}

//--------------------------------------------------------------
void ofApp::update(){
    zerotopi+=0.05;
    if (zerotopi>=2*PI){
        zerotopi=0;
    }
    
    pedalRPosition.x=pedalRadius*cos(zerotopi)+pedalierCenter.x;
    pedalRPosition.y=pedalRadius*sin(zerotopi)+pedalierCenter.y;
    
    kneeRPosition.y+=cos(zerotopi);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofDrawBitmapString("Mouse Position: "+ofToString(mousePosition.x)+"x"+ofToString(mousePosition.y)+"y", ofPoint(5,20));
    /*ofSetColor(255, 255, 255);
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
    ofPopStyle();*/
    
    ofSetLineWidth(12);
    
    //head
    ofCircle(bikerOrigin.x, bikerOrigin.y-300, 30);

    //leftarm
    ofSetColor(0,255,0);
    ofLine(bikerOrigin.x, bikerOrigin.y-240, bikerOrigin.x+125, bikerOrigin.y-140);
    
    //left cuixa
    //ofLine(ofPoint(bikerOrigin.x, bikerOrigin.y-100), kneeLPosition);

    //bike
    ofSetColor(255);
    bike.draw(bikerOrigin.x-bike.width/2+90, bikerOrigin.y-bike.height/2+20);
    
    //things draw top of bike
    
    //body
    ofSetColor(255);
    ofEllipse(bikerOrigin.x, bikerOrigin.y-170, 100, 200);
    
    //right arm
    ofSetColor(255,250,0);
    ofLine(bikerOrigin.x, bikerOrigin.y-240, bikerOrigin.x+120, bikerOrigin.y-135);
    
    
    //right cuixa
    ofLine(ofPoint(bikerOrigin.x, bikerOrigin.y-100), kneeRPosition);
    
    
    //draw pedal arm
    ofSetColor(70);
    ofLine(pedalierCenter, pedalRPosition);
    
    //center of pedalier
    ofCircle(pedalierCenter, 9);
    
    //right cama
    ofSetColor(4,242,14);
    ofLine(kneeRPosition, pedalRPosition);
    
    
    //draw pedal
    ofSetColor(255, 0, 0);
    ofRect(pedalRPosition.x-10, pedalRPosition.y-2.5, 20, 5);

    
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    //ofBackground(rand()*255, rand()*255,rand()*255);
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
  //prova
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
//prova2
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
