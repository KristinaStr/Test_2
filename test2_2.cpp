#include <iostream>
#include <sstream>
#include <string>

using namespace std;

bool read(double *mas, int k){
    string stroka;
    getline(cin, stroka);
    istringstream stream(stroka);
    for(unsigned int i=0; i<k; ++i){
        if(!(stream>>mas[i])){
            cout<<"Error_1"<<endl; //проверка (все ли элементы вводятся)
            return false;
        }
    }
    if(!(stream.eof())){
        cout<<"error_2"<<endl; //проверка (нет ли избытка элементов)
        return false;
    }
}

void sdvig(double *mas, int k, int sd){
    double *mas_left=new double[k-sd];
    double *mas_right=new double[sd];
    for(unsigned int i=0; i<k; ++i){
        if(i<k-sd){
            mas_left[i]=mas[i];
        }
        else{
            mas_right[i+sd-k]=mas[i];
        }
    }
    for(unsigned int i=0; i<(k-sd)/2; ++i){
        swap(mas_left[i], mas_left[k-sd-1-i]);
    }
    for(unsigned int i=0; i<sd/2; ++i){
        swap(mas_right[i], mas_right[sd-1-i]);
    }
    for(unsigned int i=0; i<k; ++i){
        if(i<k-sd){
            mas[i]=mas_left[i];
        }
        else{
            mas[i]=mas_right[i+sd-k];
        }
    }
    for(unsigned int i=0; i<k/2; ++i){
        swap(mas[i],mas[k-1-i]);
    }
}

int main(){
    int k;
    string n;
    getline(cin, n);
    istringstream stream(n);
    if(!(stream>>k)||(k<0)){
        cout<<"Error_1"<<endl;//проверка (вводится ли элемент с кл-ры + проверка на неотрицательность)
        return -1;
    }
    double *array=new double[k];
    if(read(array, k)){
        int sd;
        string s1;
        getline(cin, s1);
        istringstream stream1(s1);
        if(!(stream1>>sd)||(sd<0)){
            cout<<"An error has occured while reading input data."<<endl; //проверка (вводится ли элемент сдвига с кла-ры + не отрицательный ли он)
            return -2;
        }
        sdvig(array, k, sd);
        for(unsigned int i=0; i<k; ++i){
            cout<<array[i]<<" ";
        }
    }
    delete[]array;
    return 0;
}
