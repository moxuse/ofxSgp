#include "testApp.h"

#define EARTH_SIZE          (6378)

//--------------------------------------------------------------
void testApp::setup(){
	
    cameraDistance = 40000;
    camera.setFov( 45.8 );
    camera.setFarClip( 90000.f );

    ofBackground( 0, 0, 0 );
    ofSetFrameRate( 30 );

    //load TLE file
    const char * tleFilePath = "/prism.txt"; //Path of TLE File

    //setup ofxSgp with TLE file path
    sgp.setup( tleFilePath );

    earth.mID = 0;
    satellite.mID = 1;
}

//--------------------------------------------------------------
void testApp::update(){
    
    ofQuaternion latRot;
    ofQuaternion lonRot;
	
    camera.orbit( (float)mouseX / ofGetWidth() * 360, (float)mouseY / ofGetHeight() *180, cameraDistance, ofVec3f( 0, 0, cameraDistance ) );

    camera.lookAt( ofVec3f( 0, 0, 0 ) );

    ofVec3f satPos;

    //get 3D position of satellite with coordination info.
    sgp.update();
    
    satellite.setPosition(0, 0, _sgp.getSatAlt() + EARTH_SIZE);
    latRot.makeRotate(-_sgp.getSatLatitude(), 1, 0, 0);
    lonRot.makeRotate(_sgp.getSatLongitude(), 0, 1, 0);

}

//--------------------------------------------------------------
void testApp::draw(){
    
    camera.begin();
    ofDrawAxis( 1000 );

    earth.setPosition( 0, 0, 0 );
    earth.draw();

    satellite.draw();
    camera.end();
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}