#ifdef __APPLE__
# include <OpenGL/gl.h>
# include <OpenGL/glu.h>
# include <GLUT/glut.h>
#else
# include <GL/gl.h>
# include <GL/glu.h>
# include <GL/glut.h>
#endif

int screenw;
int screenh;

void display(void){

	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	glLoadIdentity();

	gluLookAt( 0, 1.0f, 0,
			   0, 1.0f, 0,
			   0, 1.0f, 0);

	glutSwapBuffers();	
		
}

void resize( int w, int h ){
	
	screenw = w;
	screenh = h;
	if( h == 0 ){
		h = 1;
	}
	float ratio = 1.0*w/h;

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	glViewport( 0, 0, w, h );

	gluPerspective(60, ratio, 1, 1000);

	glMatrixMode(GL_MODELVIEW);

}

int main( int argc, char* argv[] ){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB );
	screenw = 1080; screenh = 720;
	glutInitWindowSize( screenw, screenh );
	glutInitWindowPosition( 10, 10 );
	glutCreateWindow("So you think you can dance");

	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutIdleFunc(display);

	glutMainLoop();
	
	return 1;
};
