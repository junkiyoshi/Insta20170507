#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofBackground(0);
	ofEnableDepthTest();

	ofSetWindowTitle("noise");
	
	ofNoFill();
	ofSetLineWidth(3);
	this->noise_z = ofRandom(10);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	cam.begin();

	float radius = 30;
	float tmp_noise_z = this->noise_z;
	ofVec3f prePosition = ofVec3f(0, 0, 0);

	float x, y, z;
	for (int i = 360 * 15; i > 0; i -= 10) {
		x = radius * cos(DEG_TO_RAD * i);
		y = radius * sin(DEG_TO_RAD * i);
		z = ofMap(ofNoise(tmp_noise_z), 0, 1, -200, 200);

		ofColor c;
		c.setHsb(i % 255, 255, 255);
		ofSetColor(c);

		ofPushMatrix();
		ofTranslate(x, y, z);
		ofEllipse(ofVec3f(0, 0, 0), 100 * ofNoise(tmp_noise_z), 100 * ofNoise(tmp_noise_z));
		ofPopMatrix();

		prePosition = ofVec3f(x, y, z);
		radius += 2.5;
		tmp_noise_z += 0.05;
	}
	
	this->noise_z += 0.05;

	cam.end();
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
