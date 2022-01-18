#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double *,int,int);

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void findColSum(const double *,double *,int,int);

int main(){
	srand(time(0));
	const int N = 6, M = 8;
	double data[N][M] = {};
	double sum1[N] = {};
	double sum2[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,sum1,N,M);
	showData(sum1,N,1);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,sum2,N,M); 
	showData(sum2,1,M);
}

void showData(double* a,int N,int M){
    cout << fixed << setprecision(2);
    for(int i = 0; i < N*M; i++){
        cout << a[i];
        if((i+1)%M == 0) cout << endl;
        else cout << " ";
    }
}

void randData(double *a,int N,int M){
    for(int i = 0; i < N*M; i++){
        *(a+i) = (double)(rand()%101)/100;
    }
}

void findRowSum(const double *a,double *b,int N,int M){
	double sum1 = 0;
	int n = 0;
	for(int i =0;i < N*M;i++){
		sum1 = sum1 + *(a+i);
		if((i+1)%M == 0){
	        *(b+n) = sum1;
	        sum1 = 0;
	        n++;
		}
	}
}

void findColSum(const double *a,double *b,int N,int M){
	double sum2 = 0;
	for(int i =0;i < M;i++){
        for(int I=0;I < N;I++){
            sum2 = sum2 + *(a+(i+M*I));
        }
        *(b+i) = sum2;
        sum2 = 0;
	}
}
