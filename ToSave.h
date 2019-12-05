#ifndef TOSAVE_H_INCLUDED
#define TOSAVE_H_INCLUDED
#include <iomanip>

void Saver(SuperArrayDim4<Link<MatrixSU2>>& arr, double & beta, TestClass & randomm, ofstream &fout)
{
    int t = ErrorNum;
    iteraction(15, arr, beta, randomm);
    for(int q = 0; q  < t; q ++){
        string filename = GetFileName(q);
        ofstream out_file;
        out_file.open(filename);
        out_file.precision(10);
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    for(int k = 0; k < n; k++)
                    {
                        for(int m = 0; m < n; m++)
                        {
                            for(int l = 0; l < 4; ++l)
                            {
                                for(int r = 0; r < 4; r ++){
                                    out_file << arr[i][j][k][m].get(l).get(r) << " ";

                                }
                            }
                        }
                    }
                }
            }
            out_file.close();
            double b = 0;
            iteraction(5, arr,beta,randomm);
    }

    cout << "done" << endl;
}

#endif // TOSAVE_H_INCLUDED
