#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    path.setFilled(false);
    path.setStrokeColor(ofColor(255));
    path.setStrokeWidth(10);

 	ofEnableDepthTest();
    int yoffset = -100;
	baseNode.setPosition(0, yoffset, 0);
    childNode.setParent(baseNode);
    childNode.setPosition(0, yoffset + 220, 0);
    grandChildNode.setParent(childNode);
    grandChildNode.setPosition(0,yoffset+200,0);
}


ofVec3f velocity;
ofVec3f target = ofVec3f(0, 100, 0);

bool mousedown = false;
bool drawNodes = true;

//--------------------------------------------------------------
void ofApp::update()
{
    // baseNode.tiltDeg(sin(ofGetElapsedTimef() + 10) / 2.0);
    // childNode.tiltDeg(sin(ofGetElapsedTimef() + 10) / 5.0);
    
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
 	
 	//Constants
    float dt = 1.0 / 60.0;         //Time step
    float mass = 0.1;              //Mass of a ball
    float rubberLen = 0.0;       //Segment's length
    float k = 15.0;                 //Segment's stiffness
    float damping = 0.5;
    ofVec3f g( 9.8, 0.0, 0.0 );         //Gravity force
    float childScale = 0.3;
    
    //Compute Hooke's force
    ofVec3f delta = grandChildNode.getGlobalPosition() - target;
    if (!mousedown)
    {
	    float len = delta.length();   //Vector's length
	    float hookeValue = k * (len - rubberLen);
	    delta.normalize();            //Normalize vector's length
	    ofVec3f hookeForce = delta * (-hookeValue);
	    ofVec3f dampingForce = damping * velocity;

	    //Update velocity and pos
	    ofVec3f force = hookeForce + g - dampingForce;  //Resulted force
	    ofVec3f a = force / mass;        //Second Newton's law
	    velocity += a * dt;              //Euler method
	    ofVec3f result = velocity * dt;
	    // grandChildNode.move(result.x, 0, 0);            //Euler method    	
	    grandChildNode.move(result);            //Euler method    	
	    childNode.move(result * childScale);
    }
    else 
    {
    	childNode.move(0, 0, (ofGetMouseX() - ofGetWidth() * 0.5) * childScale / 100.0);
    	grandChildNode.move(0, 0, (ofGetMouseX() - ofGetWidth() * 0.5) / 100.0);
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackground(55);

   	cam.begin();

   	ofSetColor(255);
   	if (drawNodes)
   	{
	   	ofDrawCircle(baseNode.getGlobalPosition(), 5);
	   	ofSetColor(255, 0, 0);
	   	ofDrawCircle(childNode.getGlobalPosition(), 5);
	   	ofSetColor(255);
	   	ofDrawCircle(grandChildNode.getGlobalPosition(), 5);
   	}

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
	switch (key)
	{
		case 'n': drawNodes = !drawNodes; break;
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	mousedown = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	mousedown = false;
	// target = ofVec3f(ofGetMouseX(), 200, 0);
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
