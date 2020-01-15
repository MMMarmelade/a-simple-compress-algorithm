using namespace std;
#include<iostream>
#include<math.h>

typedef unsigned char grayv;
const int LMAX = 256;
const int LHEAD = 11;

struct opt_sol {
	int* b;//to record the length of each grayv number
	int* l;//to record the length of last segments
	int* S;//to record the total length 
};
typedef opt_sol* optsolptr;

int min(int a, int b) {
	if (a <= b)
		return a;
	else return b;
}

/*
input:P[],the grayv sequence
output:l[],main the infomation of segments' length
*/
optsolptr compress(grayv *P,int n) {
	//initial
	int nn = sizeof(int) * (n+1);//+1 means to correspond to the natural index
	int* b=(int*)malloc(nn);//to record the length of each grayv number
	int* l = (int*)malloc(nn);//to record the length of last segments
	int* S = (int*)malloc(nn);//to record the total length 
	int bmax = 0;//the largest b[] of the later subsequence
	b[0] = 0;l[0] = 0;S[0] = 0;//the situation of the 0-length sequence
	for (int i = 1;i < n+1;i++) {//i means the end of the subproblem
		//initialize the subproblem
		//the first step of subproblem is that the later sequence has only one grayv
		b[i] = ceil(log2(P[i-1]+1));
		bmax = b[i];
		S[i] = S[i - 1] + bmax + LHEAD;//cout << S[i] << endl;
		l[i] = 1;
		int li = min(i, LMAX);
		for (int j = 2;j <= li;j++) {//j means the length of the last segment of the subproblem
			if (bmax < b[i - j + 1])
				bmax = b[i - j + 1];
			//1.the index of S is (i-j),which is the end of the previous segment
			int tempS = S[i - j] + j * bmax + LHEAD;//2.the last segments is still processing, DONOT +LHEAD
			if (tempS < S[i]) {
				S[i] = tempS;
				l[i] = j;//l[i] can be used to trackback the optimal solution
			}
		}
	}
	opt_sol* os = new opt_sol;
	os->b = b;
	os->l = l;
	os->S = S;
	return os;
}

/*trackback the optimal solution
input:l[],the length of last segments
output:C[],the length of segments
*/
int trackback(int* l,int n) {
	int* C = (int*)malloc(sizeof(int) * n);
	int i = n;
	int j = 0;
	while (i > 0) {
		cout << l[i];
		i = i - l[i];
		j++;
	}
	return j;
}


int main() {
	const int n = 6;
	grayv P[n] = { 10,12,15,225,1,2 };
	opt_sol* os = compress(P,n);
	for (int i = 1;i <= n;i++) {
		cout<<os->S[i]<<endl;
	}
	cout << "the total length:" <<os->S[n]<< endl;
	cout << "the b[]:" ;
	for (int i = 0;i <= n;i++) {
		cout << os->b[i];
	}
	cout << endl<<"the l[]:";
	for (int i = 0;i <= n;i++) {
		cout << os->l[i];
	}
	cout << endl << "trackback:";
	int C = trackback(os->l, n);
	cout << endl<<"the number of segments:"<<C << endl;
	
}
