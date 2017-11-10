#include <iostream>
#include <sstream>
#include <utility>
#include <stdlib.h>

using namespace std;
void reverse(int *mas,  int k)
{
    if (k > 0) 
    {
        for (int i = 0; i < k / 2; i++) 
        {

            swap(mas[i], mas[k - i - 1]);
        }
    }
}
    



    bool read(int *mas, int k) 
    {
        string stroka;
        getline(cin, stroka);
        istringstream stream(stroka);
        for (int i = 0; i < k; i++)
        {
            if (!(stream >> mas[i]))
            {
                cout << "Error" << endl;
                
            }
        }
        if (stream>>k)
        {
        cout<<"Error";
        exit(0);
        }
        return true;
    }


    int main() {
        int k;
        cin>> k;
        if (k>=0)
        {
    
       
    
        cin.get();
        int *mas = new int[k];
        if (read(mas, k))
        {
            reverse(mas, k);
            for (int i = 0; i < k; i++) 
            {
                cout << mas[i] << " ";
            }
        }
        }
        else 
        {
            cout<<"error";
        }
    
        return 0;
        
    }
    
