#include "GL/gl.h"
#include "SDL/SDL.h"

void initgraphics(){
   SDL_SetVideoMode(640,480,0,SDL_OPENGL);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glFrustum(-1.33,1.33,-1,1,1.5,100);
   glMatrixMode(GL_MODELVIEW);
   glEnable(GL_DEPTH_TEST);
   glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
   glLoadIdentity();
}

////////////////////////////////////////////

void on_update(){
   glBegin(GL_TRIANGLES);
   glVertex3i(1,1,-10);
   glVertex3i(1,-1,-10);
   glVertex3i(-1,1,-10);
   glEnd();
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
}
