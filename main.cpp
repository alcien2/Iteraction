#include <random>
//#include <ctime>
#include <chrono>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
//#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <complex>
#include <new>
#include <iomanip>
#include <vector>
#include <fstream>
#include "Class_SU2.h"
#include "Arrays.h"
#include "Iteractions.h"
#include "ToGet.h"
#include "functions.h"
#include "ToSave.h"


int main()
{
    TestClass randomm;
    //srand(static_cast<unsigned int>(time(0)));
    srand (time(NULL));
    ofstream ffout, fout, fout1, fout2, fout3, fout4;
    ffout.open("H = 0res2.txt");
    fout.open("H = 0res1.txt");
    fout1.open("H = 0res3.txt");
    //fout2.open("chi22.txt");
    //fout3.open("chi33.txt");
    //fout4.open("chi44.txt");

    SuperArrayDim4<Link<MatrixSU2>> *ar;
    try{
        ar = new SuperArrayDim4<Link<MatrixSU2>>(n);
    }catch(bad_alloc xa){
        cout << "yps" << endl;
        return 1;
    }
    double beta = 2.8;
    MakeArrayGreatAgain(*ar);
    //iteraction(15, *ar, beta, randomm);
    Saver(*ar, beta, randomm, ffout);
    //Sigma(*ar, randomm, fout, ffout, fout1);
    
   // Chi(*ar, randomm, fout1, fout2, fout3, fout4);
   /*
    double beta = 0.01;
    for(int q = 0; q < 16; q ++){
    MakeArrayGreatAgain(*ar);
    iteraction(iter, *ar, beta, randomm);
    /*int i,j;
    double res = 0;
    double error;
    ForWilsonloop(4,4, *ar, beta, randomm, res, error);
    cout << res << " " << error << endl;
    for(i = 1; i < 6; i ++){
        j = i;

    }
    double b = 0;
    for(int i = 0; i < 2; i++){
            for (int j = 0; j < 2; j++){
                    for (int k = 0; k < 2; k ++){
                           for (int q = 0; q < 2; q++){
                                    for (int l = 0; l < 4; l++){
                                            for(int t = 0; t < 4; t++){
                                                cout << ar[i][j][k][q].get(l).get(t) << endl;
                                                b += (*ar[i][j][k][q].get(l).get(t))*(*ar[i][j][k][q].get(l).get(t));
                                            }
                                            cout<<"sum " << b << endl;
                                            b = 0;
                                    }
                            }
            }
        }
    }
    /*double error = 0;
    //double loop = Average(*ar);
    double loop = Wilsonloop(*ar, error, beta, randomm);
    //double loop = Wilsonloop(ar);
    fout << "{{" << beta << ","<< loop << "}, ErrorBar[" << error << "]},";
    cout << loop <<" " << error << endl;
    beta += 0.25;
    //iter ++;
    }*/
    fout1.close();
  //fout2.close();
  //fout3.close();
  //fout4.close();
    ffout.close();
    fout.close();
    return 0;
}
