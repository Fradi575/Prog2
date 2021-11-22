/*
    g++ kocka2.cpp Graph.cpp Window.cpp GUI.cpp -o kocka `fltk-config --ldflags --use-images`
*/
#include "Lines_window2.h"
#include "Graph.h"
#include <ctime>

//Az orange az most drag lesz.



int main(){

Lines_window win{Point{100,100}, 1920, 1080, "Kocka"};

for (int i = 0; i<12; ++i)
for (int j = 0; j<9; ++j) {
win.vr.push_back(new Rectangle{Point{i*40,j*40},40,40});
win.prev.push_back(new Rectangle{Point{i*40+300,j*40+300},10,10});

if(i==3 || i==4 || i==5 || j==3 || j==4 || j==5){
win.attach(win.vr[win.vr.size()-1]);
//win.attach(prev[prev.size()-1]);
}
if ((i==3 && (j==0 || j==1 || j==2)) || (i==4 && (j==0 || j==1 || j==2)) || (i==5 && (j==0 || j==1 || j==2))){
	win.vr[win.vr.size()-1].set_fill_color(Color::white);
	win.attach(win.vr[win.vr.size()-1]);
	win.prev[win.prev.size()-1].set_fill_color(Color::white);
	//win.attach(prev[prev.size()-1]);
}
else if ((i==0 && (j==3 || j==4 || j==5)) || (i==1 && (j==3 || j==4 || j==5)) || (i==2 && (j==3 || j==4 || j==5))){
	win.vr[win.vr.size()-1].set_fill_color(Color::drag);
	win.attach(win.vr[win.vr.size()-1]);
	win.prev[win.prev.size()-1].set_fill_color(Color::drag);
	//win.attach(prev[prev.size()-1]);
}
else if ((i==3 && (j==3 || j==4 || j==5)) || (i==4 && (j==3 || j==4 || j==5)) || (i==5 && (j==3 || j==4 || j==5))){
	win.vr[win.vr.size()-1].set_fill_color(Color::green);
	win.attach(win.vr[win.vr.size()-1]);
	win.prev[win.prev.size()-1].set_fill_color(Color::green);
	//win.attach(prev[prev.size()-1]);
}
else if ((i==6 && (j==3 || j==4 || j==5)) || (i==7 && (j==3 || j==4 || j==5)) || (i==8 && (j==3 || j==4 || j==5))){
	win.vr[win.vr.size()-1].set_fill_color(Color::red);
	win.attach(win.vr[win.vr.size()-1]);
	win.prev[win.prev.size()-1].set_fill_color(Color::red);
	//win.attach(prev[prev.size()-1]);
}
else if ((i==9 && (j==3 || j==4 || j==5)) || (i==10 && (j==3 || j==4 || j==5)) || (i==11 && (j==3 || j==4 || j==5))){
	win.vr[win.vr.size()-1].set_fill_color(Color::blue);
	win.attach(win.vr[win.vr.size()-1]);
	win.prev[win.prev.size()-1].set_fill_color(Color::blue);
	//win.attach(prev[prev.size()-1]);
}
else if ((i==3 && (j==6 || j==7 || j==8)) || (i==4 && (j==6 || j==7 || j==8)) || (i==5 && (j==6 || j==7 || j==8))){
	win.vr[win.vr.size()-1].set_fill_color(Color::yellow);
	win.attach(win.vr[win.vr.size()-1]);
	win.prev[win.prev.size()-1].set_fill_color(Color::yellow);
	//win.attach(prev[prev.size()-1]);
}
  
}



return gui_main();


}




Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    :Window{xy,w,h,title},
    
    F_button{Point{x_max()-300,400}, 50, 50, "F",
        [](Address, Address pw) {reference_to<Lines_window>(pw).F();}},
    U_button{Point{x_max()-250,400}, 50, 50, "R",
        [](Address, Address pw) {reference_to<Lines_window>(pw).R();}},
    R_button{Point{x_max()-200,400}, 50, 50, "U",
        [](Address, Address pw) {reference_to<Lines_window>(pw).U();}},
    B_button{Point{x_max()-150,400}, 50, 50, "B",
        [](Address, Address pw) {reference_to<Lines_window>(pw).B();}},
    D_button{Point{x_max()-100,400}, 50, 50, "L",
        [](Address, Address pw) {reference_to<Lines_window>(pw).L();}}, 
    L_button{Point{x_max()-50,400}, 50, 50, "D",
        [](Address, Address pw) {reference_to<Lines_window>(pw).D();}},
    reset_button{Point{x_max()-200,200}, 150, 50, "Ujrakezd",
        [](Address, Address pw) {reference_to<Lines_window>(pw).reset();}},
    mix_button{Point{x_max()-400,200}, 150, 50, "Kever",
        [](Address, Address pw) {reference_to<Lines_window>(pw).mix();}}
    
{
    
    attach(F_button);
    attach(U_button);
    attach(R_button);
    attach(B_button);
    attach(D_button);
    attach(L_button);
    attach(reset_button);
    attach(mix_button);
/*  attach(next_time);
    attach(average);
    attach(time);
    attach(avg); */
}



void Lines_window::mix()
{
   int kever_max=20;
   
   for(int i=0;i<kever_max;i++){
   int r=rand()%6+1;
   if(r==1)      F();
   else if(r==2) R();
   else if(r==3) U();
   else if(r==4) B();
   else if(r==5) L();
   else if(r==6) D();
    
}
   redraw();
}
void Lines_window::F()
{
    
    vr[21].set_fill_color(prev[33].fill_color());
    vr[22].set_fill_color(prev[42].fill_color());
    vr[23].set_fill_color(prev[51].fill_color());
    vr[33].set_fill_color(prev[59].fill_color());
    vr[42].set_fill_color(prev[58].fill_color());
    vr[51].set_fill_color(prev[57].fill_color());
    vr[57].set_fill_color(prev[29].fill_color());
    vr[58].set_fill_color(prev[38].fill_color());
    vr[59].set_fill_color(prev[47].fill_color());
    vr[29].set_fill_color(prev[23].fill_color());
    vr[38].set_fill_color(prev[22].fill_color());
    vr[47].set_fill_color(prev[21].fill_color());
    
    vr[30].set_fill_color(prev[32].fill_color());
    vr[31].set_fill_color(prev[41].fill_color());
    vr[32].set_fill_color(prev[50].fill_color());
    vr[39].set_fill_color(prev[31].fill_color());
    vr[41].set_fill_color(prev[49].fill_color());
    vr[48].set_fill_color(prev[30].fill_color());
    vr[49].set_fill_color(prev[39].fill_color());
    vr[50].set_fill_color(prev[48].fill_color());
    for(int i=0; i<vr.size(); i++) 
    prev[i].set_fill_color(vr[i].fill_color());
    
    redraw();
    
    }
    

void Lines_window::R()
{
    
    
    vr[45].set_fill_color(prev[48].fill_color());
    vr[46].set_fill_color(prev[49].fill_color());
    vr[47].set_fill_color(prev[50].fill_color());
    vr[48].set_fill_color(prev[51].fill_color());
    vr[49].set_fill_color(prev[52].fill_color());
    vr[50].set_fill_color(prev[53].fill_color());
    vr[51].set_fill_color(prev[86].fill_color());
    vr[52].set_fill_color(prev[85].fill_color());
    vr[53].set_fill_color(prev[84].fill_color());
    vr[84].set_fill_color(prev[47].fill_color());
    vr[85].set_fill_color(prev[46].fill_color());
    vr[86].set_fill_color(prev[45].fill_color());
    
    vr[57].set_fill_color(prev[59].fill_color());
    vr[58].set_fill_color(prev[68].fill_color());
    vr[59].set_fill_color(prev[77].fill_color());
    vr[66].set_fill_color(prev[58].fill_color());
    
    vr[68].set_fill_color(prev[76].fill_color());
    vr[75].set_fill_color(prev[57].fill_color());
    vr[76].set_fill_color(prev[66].fill_color());
    vr[77].set_fill_color(prev[75].fill_color());
    
    for(int i=0; i<vr.size(); i++) 
    prev[i].set_fill_color(vr[i].fill_color());
    
    redraw();
}    

void Lines_window::U(){

    vr[3].set_fill_color(prev[30].fill_color());
    vr[12].set_fill_color(prev[39].fill_color());
    vr[21].set_fill_color(prev[48].fill_color());
    vr[30].set_fill_color(prev[57].fill_color());
    vr[39].set_fill_color(prev[66].fill_color());
    vr[48].set_fill_color(prev[75].fill_color());
    vr[57].set_fill_color(prev[84].fill_color());
    vr[66].set_fill_color(prev[93].fill_color());
    vr[75].set_fill_color(prev[102].fill_color());
    vr[84].set_fill_color(prev[3].fill_color());
    vr[93].set_fill_color(prev[12].fill_color());
    vr[102].set_fill_color(prev[21].fill_color());
    
    vr[27].set_fill_color(prev[29].fill_color());
    vr[28].set_fill_color(prev[38].fill_color());
    vr[29].set_fill_color(prev[47].fill_color());
    vr[36].set_fill_color(prev[28].fill_color());
    
    vr[38].set_fill_color(prev[46].fill_color());
    vr[45].set_fill_color(prev[27].fill_color());
    vr[46].set_fill_color(prev[36].fill_color());
    vr[47].set_fill_color(prev[45].fill_color());
    
    for(int i=0; i<vr.size(); i++) 
    prev[i].set_fill_color(vr[i].fill_color());

    redraw();
    
}

void Lines_window::B()
{
     
    vr[3].set_fill_color(prev[45].fill_color());
    vr[4].set_fill_color(prev[36].fill_color());
    vr[5].set_fill_color(prev[27].fill_color());
    vr[27].set_fill_color(prev[75].fill_color());
    vr[36].set_fill_color(prev[76].fill_color());
    vr[45].set_fill_color(prev[77].fill_color());
    vr[75].set_fill_color(prev[53].fill_color());
    vr[76].set_fill_color(prev[44].fill_color());
    vr[77].set_fill_color(prev[35].fill_color());
    vr[35].set_fill_color(prev[3].fill_color());
    vr[44].set_fill_color(prev[4].fill_color());
    vr[53].set_fill_color(prev[5].fill_color());
    
    vr[84].set_fill_color(prev[86].fill_color());
    vr[85].set_fill_color(prev[95].fill_color());
    vr[86].set_fill_color(prev[104].fill_color());
    vr[93].set_fill_color(prev[85].fill_color());
    
    vr[95].set_fill_color(prev[103].fill_color());
    vr[102].set_fill_color(prev[84].fill_color());
    vr[103].set_fill_color(prev[93].fill_color());
    vr[104].set_fill_color(prev[102].fill_color());
    
    for(int i=0; i<vr.size(); i++) 
    prev[i].set_fill_color(vr[i].fill_color());
    
    redraw();    
     
}

void Lines_window::L(){



//L
    vr[27].set_fill_color(prev[104].fill_color());
    vr[28].set_fill_color(prev[103].fill_color());
    vr[29].set_fill_color(prev[102].fill_color());
    vr[30].set_fill_color(prev[27].fill_color());
    vr[31].set_fill_color(prev[28].fill_color());
    vr[32].set_fill_color(prev[29].fill_color());
    vr[33].set_fill_color(prev[30].fill_color());
    vr[34].set_fill_color(prev[31].fill_color());
    vr[35].set_fill_color(prev[32].fill_color());
    vr[102].set_fill_color(prev[35].fill_color());
    vr[103].set_fill_color(prev[34].fill_color());
    vr[104].set_fill_color(prev[33].fill_color());
    
    vr[3].set_fill_color(prev[5].fill_color());
    vr[4].set_fill_color(prev[14].fill_color());
    vr[5].set_fill_color(prev[23].fill_color());
    vr[12].set_fill_color(prev[4].fill_color());
    
    vr[14].set_fill_color(prev[22].fill_color());
    vr[21].set_fill_color(prev[3].fill_color());
    vr[22].set_fill_color(prev[12].fill_color());
    vr[23].set_fill_color(prev[21].fill_color());
    
    for(int i=0; i<vr.size(); i++) 
    prev[i].set_fill_color(vr[i].fill_color());
    
    redraw();

}
 
void Lines_window::D()
{


//D
    vr[5].set_fill_color(prev[86].fill_color());
    vr[14].set_fill_color(prev[95].fill_color());
    vr[23].set_fill_color(prev[104].fill_color());
    vr[32].set_fill_color(prev[5].fill_color());
    vr[41].set_fill_color(prev[14].fill_color());
    vr[50].set_fill_color(prev[23].fill_color());
    vr[59].set_fill_color(prev[32].fill_color());
    vr[68].set_fill_color(prev[41].fill_color());
    vr[77].set_fill_color(prev[50].fill_color());
    vr[86].set_fill_color(prev[59].fill_color());
    vr[95].set_fill_color(prev[68].fill_color());
    vr[104].set_fill_color(prev[77].fill_color());
    
    vr[33].set_fill_color(prev[35].fill_color());
    vr[34].set_fill_color(prev[44].fill_color());
    vr[35].set_fill_color(prev[53].fill_color());
    vr[42].set_fill_color(prev[34].fill_color());
    
    vr[44].set_fill_color(prev[52].fill_color());
    vr[51].set_fill_color(prev[33].fill_color());
    vr[52].set_fill_color(prev[42].fill_color());
    vr[53].set_fill_color(prev[51].fill_color());
    
    for(int i=0; i<vr.size(); i++) 
    prev[i].set_fill_color(vr[i].fill_color());

    redraw();
    
}  

void Lines_window::reset(){

for (int i = 0; i<vr.size(); ++i){

if(i==3 || i==4 || i==5 || i==12 || i==13 || i==14 || i==21 || i==22 || i==23) vr[i].set_fill_color(Color::drag);

else if(i==27 || i==28 || i==29 || i==36 || i==37 || i==38 || i==45 || i==46 || i==47) vr[i].set_fill_color(Color::white);

else if(i==30 || i==31 || i==32 || i==39 || i==40 || i==41 || i==48 || i==49 || i==50) vr[i].set_fill_color(Color::green);

else if(i==33 || i==34 || i==35 || i==42 || i==43 || i==44 || i==51 || i==52 || i==53) vr[i].set_fill_color(Color::yellow);

else if(i==57 || i==58 || i==59 || i==66 || i==67 || i==68 || i==75 || i==76 || i==77) vr[i].set_fill_color(Color::red);

else vr[i].set_fill_color(Color::blue);

prev[i].set_fill_color(vr[i].fill_color()); }

redraw();
} 


/*void Lines_window::time()
{
    int x = next_time.get_int();
    int szamlalo=0;
    for(int i=0; i<5; i++) szamlalo+=x;
    float y = szamlalo/5;
    average.put(y);

    redraw();
}
*/
    
