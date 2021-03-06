#include <bits/stdc++.h>
#include <algorithm>
 
using namespace std;
 
#define ENDLINE printf("\n");
#define HEY printf("HEY\n");
#define HEYA printf("HEY_A\n");
#define HEYB printf("HEY_B\n");
#define HEY2 printf("   HEY\n");
#define HEY3 printf("       HEY\n");
#define END ("\n")
#define for0(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define for1(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b)for(__typeof(b)i = a ; i <= (b) ; i++)
 
#define pm(mapa,n,m) \
    for0(i,n)       \
    {               \
        for0(j,m)   \
        {           \
            cout << "[" << mapa[i][j] << "]";    \
        }ENDLINE    \
    }   \
 
#define pa(array,n) \
    {               \
    for0(i,n)       \
    {               \
        cout << "[" << array[i] << "]"; \
    }               \
    ENDLINE;        \
    }               \
 
#define ps(s) printf("%s\n",s);

#define MAX 10000

vector< vector<char> > mapa;	
struct pos
{
	int x,y; 
	pos()
	{
	
	}
	pos(int x,int y) {this->x = x, this->y = y;}
};
queue<pos> contaminados;
int  valido(int x, int y,int N, int M)
{
	return x >= 0 && y >= 0 && x < N && y < M;
}

void add_adj(pos contaminado, int N, int M)
{
	if(valido(contaminado.x+1,contaminado.y,N,M) && mapa[contaminado.x+1][contaminado.y] == 'A')	
	{
		mapa[contaminado.x+1][contaminado.y] = 'T';
		contaminados.push(pos(contaminado.x+1,contaminado.y));
	}
	if(valido(contaminado.x-1,contaminado.y,N,M) && mapa[contaminado.x-1][contaminado.y] == 'A')
	{
		mapa[contaminado.x-1][contaminado.y] = 'T';
		contaminados.push(pos(contaminado.x-1,contaminado.y));
	}
	if(valido(contaminado.x,contaminado.y+1,N,M) && mapa[contaminado.x][contaminado.y+1] == 'A')
	{
		mapa[contaminado.x][contaminado.y+1] = 'T';
		contaminados.push(pos(contaminado.x,contaminado.y+1));
	}
	if(valido(contaminado.x,contaminado.y-1,N,M) && mapa[contaminado.x][contaminado.y-1] == 'A')
	{
		mapa[contaminado.x][contaminado.y-1] = 'T';
		contaminados.push(pos(contaminado.x,contaminado.y-1));
	}		
}

int main()
{
	int N,M;
	
	while(cin >> N >> M && N && M)
	{
		for(auto &row : mapa)
		{	
			row.clear();
		}
		
		for0(i,N)
		{
			vector<char> row; mapa.push_back(row);
			for0(j,M)
			{
				char value; cin >> value;
				mapa[i].push_back(value);
				if(value == 'T') contaminados.push(pos(i,j));
			}
		}							

		while(!contaminados.empty())
		{
			pos contaminado = contaminados.front(); contaminados.pop();
	
			mapa[contaminado.x][contaminado.y] = 'T';
	
			add_adj(contaminado,N,M);
		}

		for(int i = 0; i< N;i++)
		{

			for0(j,M)
			{
				printf("%c",mapa[i][j]);
			}
			ENDLINE;	
		}	
		ENDLINE;
	}	
}
















