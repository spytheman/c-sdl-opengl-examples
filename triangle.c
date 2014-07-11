#include "GL/gl.h"
#include "SDL/SDL.h"

void initgraphics(){
   SDL_SetVideoMode(640,480,0,SDL_OPENGL);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glFrustum(-1.33,1.33,-1,1,1.5,100);
   glMatrixMode(GL_MODELVIEW);
   
   glEnable(GL_BLEND);
   glDisable( GL_DEPTH_TEST );
   glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
   glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);   
   //Set antialiasing/multisampling
   glHint( GL_LINE_SMOOTH_HINT, GL_NICEST );
   glHint( GL_POLYGON_SMOOTH_HINT, GL_NICEST );

   glDisable( GL_LINE_SMOOTH );
   glDisable( GL_POLYGON_SMOOTH );
   glEnable( GL_MULTISAMPLE );
      
   glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
   
}

////////////////////////////////////////////

double ang = 0;

void on_update(){
   glClearColor(0,0,255,1);
   glClearDepth(1.0f);
   glClear(GL_COLOR_BUFFER_BIT);

   glDisable( GL_LINE_SMOOTH );
   glDisable( GL_POLYGON_SMOOTH );
   glEnable( GL_MULTISAMPLE );
   

   glPushMatrix();   
   glTranslatef(-1.0,0.0,0.0); 
   glRotated(ang++, 0.1, -0.1, -1.0);
   glTranslatef(-1.0,0.0,0.0);
   
   glColor3f(0.0,1.0,0.0);
   glBegin(GL_TRIANGLES);
   glVertex3d(5.0,   3.0, -10.0);
   glVertex3d(5.0,  -3.0, -10.0);
   glVertex3d(-5.0,  3.0, -10.0);
   glEnd();

   glDisable( GL_MULTISAMPLE );
   
   glPopMatrix();
   
   
   
   SDL_GL_SwapBuffers();
}

////////////////////////////////////////////

void loop(){
   SDL_Event event;   
   do{
      on_update();
      SDL_PollEvent(&event);
   }while (event.type!=SDL_KEYDOWN);      
   SDL_Quit();
}

////////////////////////////////////////////

int main(){
   initgraphics();   
   loop();
   printf("%f\n", ang);
}
