#ifndef ARRAYS_H_INCLUDED
#define ARRAYS_H_INCLUDED

const int MaxSize = 15;
const double phi = 0;
//const double beta = 2.6;
using namespace std;

template <typename Type>
class SuperArray {
private:
    int arrsize;
public:
    SuperArray(){}
    SuperArray(int s){
        arrsize = s;
    }
    Type arr[MaxSize];


    Type& operator[] (int k);
};

template <typename Type>
Type& SuperArray<Type>::operator[] (int k) {
   /* if((k % arrsize == 0) && k != 0 ){
    double f[4] = {cos(phi), 0, 0, sin(phi)};
    MatrixSU2 phase;
    phase.set_matrix(f);
    arr[k] = arr[0];
    arr[k].get(1) = arr[0].get(1) * phase;
        return arr[k];
    }
    else{*/
        return arr[k >= 0 ? k % arrsize : arrsize + k % arrsize];
    //}
}

template <typename Type>
class SuperArrayDim2 {
    int arrsize;
public:
    SuperArrayDim2() {}
    SuperArrayDim2(int s){
        arrsize = s;
        for(int i = 0; i < MaxSize; i++){
            arr[i] = SuperArray<Type>(s);
        }
    }
    SuperArray<Type> arr[MaxSize];

    SuperArray<Type>& operator[](int k);
    };

template <typename Type>
SuperArray<Type>& SuperArrayDim2<Type>::operator[] (int k) {
    return arr[k >= 0 ? k % arrsize : arrsize + k % arrsize];
}

template <typename Type>
class SuperArrayDim3 {
    int arrsize;
public:
    SuperArrayDim3() {}
    SuperArrayDim3(int s){
        arrsize = s;
        for(int i = 0; i < MaxSize; i++){
            arr[i] = SuperArrayDim2<Type>(s);
        }
    }
    SuperArrayDim2<Type> arr[MaxSize];

    SuperArrayDim2<Type>& operator[](int k);
    };

template <typename Type>
SuperArrayDim2<Type>& SuperArrayDim3<Type>::operator[] (int k) {
    return arr[k >= 0 ? k % arrsize : arrsize + k % arrsize];
}

template <typename Type>
class SuperArrayDim4 {
    int arrsize;
public:
    SuperArrayDim4() {}
    SuperArrayDim4(int s){
        arrsize = s;
        for(int i = 0; i < MaxSize; i++){
            arr[i] = SuperArrayDim3<Type>(s);
        }
    }
    SuperArrayDim3<Type> arr[MaxSize];

    SuperArrayDim3<Type>& operator[](int k);
    };

template <typename Type>
SuperArrayDim3<Type>& SuperArrayDim4<Type>::operator[] (int k) {
    return arr[k >= 0 ? k % arrsize : arrsize + k % arrsize];
}

template <typename Type>
class Link{
    Type a[4];
public:
    Link(){}
    Type& get(int i) {
        if(i < 0 || i > 3)
            cout << "error in link" << endl;
        return a[i];
    }

};


#endif // ARRAYS_H_INCLUDED
