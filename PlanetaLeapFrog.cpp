/* 
 Algoritmo Leap Frog

 Problema:
 Simular el movimiento de un planeta por Euler
*/


#include <iostream>
#include <cmath>
#include "Vector.h"
using namespace std;

const double GM=1.0;

class Cuerpo{
private:
  vector3D r,V,F; double m,R;
public:
  void Inicie(double x0,double y0,double Vx0,double Vy0,double m0,double R0);
  void CalculeFuerza(void);
  void Arranque(double dt);
  void CalculeVelocidad(double dt);
  void Muevase(double dt);
  void Dibujese(void);
  double Getx(void){return r.x();}; //inline
  double Gety(void){return r.y();}; //inline
};
void Cuerpo::Inicie(double x0,double y0,double Vx0,double Vy0,double m0,double R0){
  r.cargue(x0,y0,0); V.cargue(Vx0,Vy0,0);  m=m0;  R=R0; 
} 
void Cuerpo::CalculeFuerza(void){
  double aux=GM*m*pow(norma2(r),-1.5);
  F = -aux*r;
} 
void Cuerpo::Arranque(double dt){
  V-=F*(dt/(2*m));
}
void Cuerpo::CalculeVelocidad(double dt){
  V+=F*(dt/m);
}
void Cuerpo::Muevase(double dt){
  r+=V*dt;
}
//----------------- Funciones de Animacion ----------
void Cuerpo::Dibujese(void){
  cout<<" , "<<r.x()<<"+"<<R<<"*cos(t),"<<r.y()<<"+"<<R<<"*sin(t)";
}
void InicieAnimacion(void){
  //  cout<<"set terminal gif animate"<<endl; 
  //  cout<<"set output 'Balon.gif'"<<endl;
  cout<<"unset key"<<endl;
  cout<<"set xrange[-12:12]"<<endl;
  cout<<"set yrange[-12:12]"<<endl;
  cout<<"set size ratio -1"<<endl;
  cout<<"set parametric"<<endl;
  cout<<"set trange [0:7]"<<endl;
  cout<<"set isosamples 12"<<endl;  
}
void InicieCuadro(void){
    cout<<"plot 0,0 ";
}
void TermineCuadro(void){
    cout<<endl;
}

//-----------  Programa Principal --------------  
int main(void){
  Cuerpo Planeta;
  double r0=10, m0=1;
  double omega,V0,T;
  omega=sqrt(GM/(r0*r0*r0)); T=2*M_PI/omega; V0=r0*omega;
  double t,tdibujo,tmax=3.3*T,tcuadro=T/100,dt=0.001;

  //InicieAnimacion(); //Dibujar

  //------------(x0,y0,Vx0,Vy0, m0, R0)
  Planeta.Inicie(r0, 0,  0,V0, m0,0.5);
  Planeta.CalculeFuerza();
  Planeta.Arranque(dt);
  
  for(t=0,tdibujo=0 ; t<tmax ; t+=dt,tdibujo+=dt){
    //Dibujar
    if(tdibujo>tcuadro){
      /*
      InicieCuadro();
      Planeta.Dibujese();
      TermineCuadro();
      */
      cout<<Planeta.Getx()<<" "<<Planeta.Gety()<<endl;
    }
    Planeta.CalculeFuerza();
    Planeta.CalculeVelocidad(dt);   
    Planeta.Muevase(dt);
  }   
  return 0;
}