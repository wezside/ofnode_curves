#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    path.setFilled(false);
    path.setStrokeColor(ofColor(255));
    path.setStrokeWidth(10);

 	ofEnableDepthTest();
    int yoffset = 0;
	baseNode.setPosition(0, yoffset, 0);
    childNode.setParent(baseNode);
    childNode.setPosition(0, yoffset + 100, 0);
    grandChildNode.setParent(childNode);
    grandChildNode.setPosition(-100,yoffset+200,0);
}

//--------------------------------------------------------------
void ofApp::update()
{
    baseNode.tiltDeg(sin(ofGetElapsedTimef() + 10) / 2.0);
    childNode.tiltDeg(sin(ofGetElapsedTimef() + 10) / 5.0);
    
    points.clear();
    points.push_back(baseNode.getGlobalPosition());
    points.push_back(baseNode.getGlobalPosition());
    points.push_back(childNode.getGlobalPosition());
    points.push_back(grandChildNode.getGlobalPosition());
    points.push_back(grandChildNode.getGlobalPosition());

    path.clear();
    for (unsigned int i = 0; i < points.size(); i++) 
    {
        path.curveTo(points[i].x, points[i].y, points[i].z);
    }

    grandChildNode.move(sin(ofGetElapsedTimef() + 20), 0, 0);
    childNode.move(sin(ofGetElapsedTimef() + 10), 0, 0);
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackground(0);

   	cam.begin();
    // baseNode.draw();
    // childNode.draw();
    // grandChildNode.draw();

   	ofSetColor(255, 0, 0);
   	ofDrawCircle(baseNode.getGlobalPosition(), 10);
   	ofDrawCircle(childNode.getGlobalPosition(), 10);
   	ofDrawCircle(grandChildNode.getGlobalPosition(), 10);

    ofSetColor(255);
	path.draw();
	cam.end();
	

 /*   ofMesh meshy;
    meshy.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
	float widthSmooth = 10;
    float angleSmooth;
    for (int i = 0;  i < path.getOutline().getVertices().size(); i++)
    {
        int me_m_one = i-1;
        int me_p_one = i+1;
        if (me_m_one < 0) me_m_one = 0;
        if (me_p_one ==  path.getOutline().getVertices().size()) me_p_one =  path.getOutline().getVertices().size()-1;
        
        ofPoint diff = path.getOutline().getVertices()[me_p_one] - path.getOutline().getVertices()[me_m_one];
        float angle = atan2(diff.y, diff.x);
        
        if (i == 0) angleSmooth = angle;
        else {
            
            angleSmooth = ofLerpDegrees(angleSmooth, angle, 1.0);
            
        }
        
        
        float dist = diff.length();
        
        float w = ofMap(dist, 0, 20, 40, 2, true);
        
        widthSmooth = 0.9f * widthSmooth + 0.1f * w;
        
        ofPoint offset;
        offset.x = cos(angleSmooth + PI/2) * widthSmooth;
        offset.y = sin(angleSmooth + PI/2) * widthSmooth;
        
        
        
        meshy.addVertex(  path.getOutline().getVertices()[i] +  offset );
        meshy.addVertex(  path.getOutline().getVertices()[i] -  offset );
        
        
        
    }
    
    ofSetColor(0,0,0);
    meshy.draw();
    ofSetColor(100,100,100);
    meshy.drawWireframe();*/
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
