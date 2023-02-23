#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#include <bitset>
#include <string>
using namespace std;

//khai bao cau truc stack

#define max 100
int a[max];
int sp;

//tao stack rong

void init(int a[], int &sp)
{
    sp=-1;
}

//xet stack rong

int isEmpty(int a[], int sp)
{
    if(sp==-1)
        return 1;
    else
        return 0; //tai sao khong dung else
}

//xet stack day

int isFull(int a[], int sp)
{
    if(sp==max-1)
        return 1;
    else
        return 0;
}

//them phan tu vao stack

int push(int a[], int &sp, int x)
{
    if(sp != max-1)
    {
        a[++sp] = x;
        return 1;
    }
    else
        return 0;
}

//xuat stack tu dinh

void xuatstacktudinh(int a[], int sp)
{
	 for(int i = sp; i>= 0 ; i--)
	 cout<<a[i]<<endl;
	 cout<<endl;
}

//lay/xoa phan tu stack

int pop(int a[], int &sp, int &x)
{
    if (sp!=-1)
    {
        x=a[sp--];
        return 1;
    }
    else
        return 0;
}

//chuyen he 10 sang he 2

void convertDectoBin(int d)
{
    int du;
    while(d!=0)
    {
        du = d%2;
        push(a, sp, du);
        d = d/2;
    }
}

//in ra he 2

void printBin()
{
    int x;
    while(sp!=-1)
    {
        pop(a, sp, x);
        cout<<x;
        
    }
}

//chuyen he 10 sang he 8

void convertDectoOct(int j)
{
    int du;
    while(j!=0)
    {
        du = j%8;
        push(a, sp, du);
        j = j/8;
    }
}

//in ra he 8

void printOct()
{
    int x;
    while(sp!=-1)
    {
        pop(a, sp, x);
        cout<<x;
    }
}

//chuyen he 10 sang he 16

void covertDectoHex(int f)
{
    int du;
    while(f!=0)
    {
        du = f%16;
        push(a, sp, du);
        f = f/16;
    }
}

//in ra he 16

void printHex()
{
    int x;
    while(sp!=-1)
    {
        pop(a, sp, x);
        
        if (x < 10)
        {
            cout << x;
        }
        else
        {
            if (x == 10)
            {
                cout << "A";
            }
            else if (x == 11)
            {
                cout << "B";
            }
            else if (x == 12)
            {
                cout << "C";
            }
            else if (x == 13)
            {
                cout << "D";
            }
            else if (x == 14)
            {
                cout << "E";
            }
            else if (x == 15)
            {
                cout << "F";
            }
        }
        //cout<<x;
    }  
}


//kiem tra so nguyen to
bool ktrasonguyento(int q)
{
	if (q < 2){
        return false;
}
     for (int i = 2; i < (q - 1); i++){
        if (q % i == 0){
            return false;
        }   
    }
}

//xuat cac so nguyen to
void xuatsonguyento()
{
	int x;
	while(sp!=-1)
	{
		pop(a,sp,x);
		if (ktrasonguyento(x))
        {
            cout << x << "\t";
        }
	}
}


//lay gia tri phan tu dau stack
int top(int a[],int &sp)
{
  cout<<a[sp]<<endl;
  cout<<endl;
}

//Lay so luong phan tu stack dang co
int size(){
	return sp+1;
}

int convertBintoDec(long long z) {
  int dec = 0, i = 0, rem;

  while (z!=0) {
    rem = z % 10;
    z /= 10;
    dec += rem * pow(2, i);
    ++i;
  }

  return dec;
}


int convertOctToDec(int h)
{
    int num = h;
    int dec_value = 0;
    int base = 1;
 
    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;
        dec_value += last_digit * base;
        base = base * 8;
    }
    return dec_value;
}

int convertHextoDec(string hexVal)
{
    int len = hexVal.size();
    int base = 1;
 
    int dec_val = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (hexVal[i] >= '0' && hexVal[i] <= '9') {
            dec_val += (int(hexVal[i]) - 48) * base;
            base = base * 16;
        }

        else if (hexVal[i] >= 'A' && hexVal[i] <= 'F') {
            dec_val += (int(hexVal[i]) - 55) * base;
            base = base * 16;
        }
    }
    return dec_val;
}


void strToBinary(string s)
{
    int n = s.length();
 
 
    for (int i = 0; i <= n; i++)
    {
        int val = int(s[i]);
        string bin = "";
        while (val > 0)
        {
            (val % 2)? bin.push_back('1') :
                       bin.push_back('0');
            val /= 2;
        }
        reverse(bin.begin(), bin.end());
 
        cout << bin << " ";
    }
}


 
 
 //sap xep thu tu giam dan 
 stack<int> sortStack(stack<int> input)
{
    stack<int> tmpStack;
 
    while (!input.empty())
    {
        int tmp = input.top();
        input.pop();
        while (!tmpStack.empty() &&
                tmpStack.top() > tmp)
        {
            input.push(tmpStack.top());
            tmpStack.pop();
        }
        tmpStack.push(tmp);
    }
    return tmpStack;
}

void sortArrayUsingStacks(int a[], int sp)
{
    stack<int> input;
    for (int i=0; i<=sp; i++)
       input.push(a[i]);
 
    stack<int> tmpStack = sortStack(input);
 
    for (int i=0; i<=sp; i++)
    {
        a[i] = tmpStack.top();
        tmpStack.pop();
    }
}



int menu()
{
    int chon;
    cout<<"\n"<<"1.khoi tao stack\n"<<"2.xet rong\n"<<"3.xet day\n"<<"4.them stack\n"<<"5.xuat stack\n"<<"6.xoa stack\n"<<"7.chuyen he 10 sang he 2\n"<<"8.chuyen he 10 sang he 8\n"<<"9.chuyen he 10 sang he 16\n"<<"10.lay 1 phan tu ra khoi stack\n"<<"11.tap hop so nguyen to\n"<<"12.phan tu o dinh stack\n"<<"13.so luong phan tu trong stack\n"<<"14.sap xep stack\n"<<"15.chuyen he 2 sang he 10\n"<<"16.chuyen he 8 sang he 10\n"<<"17.chuyen ki tu sang he 2\n"<<"0.thoat\n"<<"+++++++++++++++++++++++\n"<<"chon: ";
    cin>>chon;
    return chon;
}

int main()
{
    int x, chon;
    do
    {
        chon=menu();
        switch(chon)
        {
        case 1:
            init(a, sp);
            cout<<"da khoi tao stack\n";
            break;
        case 2:
            int k;
            k = isEmpty(a, sp);
            if(k==1)
                cout<<"danh sach rong\n";
            else
                cout<<"danh sach khong rong\n";
            break;
        case 3:
            int m;
            m = isFull(a, sp);
            if(m==1)
                cout<<"danh sach day\n";
            else
                cout<<"danh sach chua day\n";
            break;
        case 4:
            cout<<"nhap gia tri can them: ";
            cin>>x;
            int n;
            n= push(a, sp, x);
            if(n==1)
                cout<<"them thanh cong\n";
            else
                cout<<"them khong thanh cong\n";
            break;
        case 5:
        	 cout<<"Cac phan tu trong stack tu dinh xuong la:\n";
             xuatstacktudinh(a, sp);
             break;
        case 6:
            int p;
            p= pop(a, sp, x);
            if (p==1)
                cout<<"xoa thanh cong\n";
            else
                cout<<"xoa khong thanh cong\n";
            break;
        case 7:
            int d;
            cout<<"nhap so he 10: ";
            cin>>d;
            convertDectoBin(d);
            cout<<"he 2: ";
            printBin();
            cout<<endl;
            break;
        case 8:
            int j;
            cout<<"nhap so he 10: ";
            cin>>j;
            convertDectoOct(j);
            cout<<"he 8: ";
            printOct();
            cout<<endl;
            break;
        case 9:
        	int f;
            cout<<"nhap so he 10: ";
            cin>>f;
            covertDectoHex(f);
            cout<<"he 16: ";
            printHex();
            cout<<endl;
            break;
		case 10:
	        int v;
	        v = pop(a,sp,x);
		    if (v == 1)
		    cout<<"Phan tu vua lay ra khoi stack:"<< x <<endl;
		    else
		    cout<<"Khong lay ra duoc phan tu tu dinh stack\n"; 
		    break;
		case 11:
		    cout<<"Cac so nguyen to trong stack la:\n";
		    xuatsonguyento();
		    cout<<endl;
		    break;
		case 12:
			cout<<"Phan tu o dinh stack:\n";
			top(a,sp);
			break;
		case 13:
			cout<<"So luong phan tu trong stack:\n"<<size();
			cout<<endl;
			break;
		case 14:
			cout<<"Sap xep giam dan:\n";
			sortArrayUsingStacks(a,sp);
			for(int i=0;i<=sp;i++)
			cout<< a[i] << " ";
			break;
	    case 15:
	    	long long z;
            cout << "nhap so he 2: ";
            cin >> z;
            cout <<  "he 10: " << convertBintoDec(z);
			break;	
		case 16:
			int h;
        	cout<< "nhap so he 8: ";
        	cin>>h;
        	cout<<  "he 10: "<<convertOctToDec(h);
        	break;
        	case 17:
        	 string s;
          cout<<"nhap ki tu: ";
          cin>>s;
          cout<<"chuyen sang he 2: ";
          strToBinary(s);
          break;
        //case 18:
              //string hexVal;
        	//cout<< "nhap so he 16: ";
        	//cin>>hexVal;
        	//cout<< "he 10: "<<convertHextoDec(hexVal);
        	//break;
             }
             }
    while (chon!=0);

}
