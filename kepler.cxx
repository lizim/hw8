#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;

void Hamiltonian(double& H, double q1, double q2, double p1, double p2);

int main (){
  
  const double ecc = 0.6;
  double H;
  
  double t = 0;
  const double tEnd = 20*M_PI;
  const double dt = 0.0005;
  //const double dt = 0.05;
  const double Nt = tEnd/dt;
  
  // Initial conditions
  double q1 = 1-ecc;
  double q2 = 0;
  
  double p1 = 0;
  double p2 = sqrt((1+ecc)/(1-ecc));
  
  ofstream out("output_hw8_Hamiltonian_0.0005.dat");
  
  Hamiltonian(H,q1,q2,p1,p2);
  
  out << t << "\t" << q1 << "\t" << q2 << "\t" << H << endl;
    
  for(int i=1; i<Nt; i++){
  
    t += dt;
    
    p1 -= dt * q1 * pow(q1*q1+q2*q2,-1.5);
    p2 -= dt * q2 * pow(q1*q1+q2*q2,-1.5);
    q1 += dt * p1;
    q2 += dt * p2;
    
    Hamiltonian(H,q1,q2,p1,p2);
    
    out << t << "\t" << q1 << "\t" << q2 << "\t" << H << endl;
  }
  
  out.close();
  
  return 0;
}

void Hamiltonian(double& H, double q1, double q2, double p1, double p2)
{
  H = 0.5 * (pow(p1,2) + pow(p2,2)) - 1.0/sqrt(pow(q1,2) + pow(q2,2));
  
}
