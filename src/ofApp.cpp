#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    cols = w / scl;
    rows = h / scl;
    
    
    
    

}


//--------------------------------------------------------------
void ofApp::draw(){
    float terrain[cols][rows];
    
    ofSetColor(ofColor::white);
    ofNoFill();
    
    flying -= 0.05;
    
    float xOff = flying;
    for (int x = 0; x < cols; x++) {
        float yOff = 0;
        for (int y = 0; y < rows; y++) {
            terrain[x][y] = ofMap(ofNoise(xOff, yOff), 0, 1, -30, 30);
            xOff += 0.1;
        }
        yOff += 0.1;
    }
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofRotateX(50);
    ofTranslate(-w/2, -h/2);
    
    for (int x = 0; x < cols; x++) {
        ofBeginShape();
        for (int y = 0; y < rows - 1; y++) {
            int randomX = ofRandom(10);
            ofVertex((x+1)*scl, y*scl, terrain[x+1][y]);
            ofVertex(x*scl, y*scl, terrain[x][y]);
            ofVertex(x*scl, (y+1)*scl, terrain[x][y+1]);
            ofVertex((x+1)*scl, y*scl, terrain[x+1][y]);
            
            
            
            /*
            triangle.addVertex(x*scl, y*scl, ofRandom(10) );
            triangle.addVertex(x*scl, (y+1)*scl, ofRandom(10) );
            */
            //ofDrawRectangle(x*scl, y*scl, scl, scl);
        }
        //triangle.close();
        //triangle.draw();
        ofEndShape();

        
    }
}

