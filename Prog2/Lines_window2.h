
#include "GUI.h"

using namespace Graph_lib;

struct Lines_window : Graph_lib::Window {
	Lines_window(Point xy, int w, int h, const string& title );
	Open_polyline lines;
	Vector_ref<Rectangle> vr;
	Vector_ref<Rectangle> prev;

	bool wait_for_button();
	
	
	Button F_button;
	Button U_button;
	Button R_button;
	Button B_button;
	Button D_button;
	Button L_button;
	Button mix_button;
	Button reset_button;
/*	Button time;
	Button avg;  */
	
	
/*	In_box next_time;
	Out_box average; */
	
	void F();
	void R();
	void U();
	void B();
	void L();
	void D();
	void reset();
	void mix();
/*	void time();
	void avg();
	
*/	

	

};
