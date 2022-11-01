#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Number;

vector<Number> v;
long long int n;

bool fraction(long long int x);
void expansion(long long int x, long long int y);
void print(long long int x, long long int y);
bool read(long long int &p,long long int &q);


int main()
{
    long long int L,M;
    
    read(L,M);
    expansion(abs(L % M), abs(M));
    print(L, M);
    
    cout << endl;
    v.clear();
    
    return 0;
}

struct Number{
	char digit;
	long long int counter;
};

bool fraction(long long int x)
{
	for (n=0; n<v.size() && v[n].counter != x; n++)
		;
	return n < v.size();
}

void expansion(long long int x, long long int y)
{
	Number e;
	for(;x!=0 && !fraction(x); x%=y)
	{
		e.counter=x;
		e.digit=(x*=10)/y;
		v.push_back(e);
	}
	if (x==0) n=v.size();
}

void print(long long int x, long long int y)
{
	if(x*y<0) cout << "-";
	cout << abs(x/y);
	if (v.empty()) return;
	cout << ".";
	for(long long int i=0; i<v.size(); i++)
	{
		if(i==n) cout << "(";
		cout << int(v[i].digit);
	}
	if (n<v.size()) cout << ")";
}

bool read(long long int &p, long long int &q)
{
	cin >> p >> q;
}
