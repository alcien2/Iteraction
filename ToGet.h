#ifndef TOGET_H_INCLUDED
#define TOGET_H_INCLUDED

 void GetArray(SuperArrayDim4<Link<MatrixSU2>>& arr, int q){
        string filename = GetFileName(q);
        ifstream in_file;
        //stringstream
        char buff[20];
        char num[12];
        in_file.open(filename);
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
                                    //in_file.getline(num, 12);
                                    in_file >> buff;
                                    arr[i][j][k][m].get(l).get(r) = atof(buff);
                                }
                            }
                        }
                    }
                }
            }
            /*double b = 0;
            for(int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    for (int k = 0; k < n; k ++){
                           for (int q = 0; q < n; q++){
                                    for (int l = 0; l < 4; l++){
                                            for(int t = 0; t < 4; t++){
                                                cout << arr[i][j][k][q].get(l).get(t) << endl;
                                                b += (arr[i][j][k][q].get(l).get(t))*(arr[i][j][k][q].get(l).get(t));
                                            }
                                            cout<<"sum " << b << endl;
                                            b = 0;
                                    }
                            }
                    }
                }
            }*/
    in_file.close();
}

#endif // TOGET_H_INCLUDED
