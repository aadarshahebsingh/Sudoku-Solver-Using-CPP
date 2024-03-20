/* Aadarsh Shaheb Singh*/
/* Created on 20-03-24*/

#include <bits/stdc++.h>
using namespace std;
#define N 9

bool isSafe(vector<vector<int>>&v,int i, int j, int x,int n)
{
    
    for(int k=0;k<n;k++)
    {
        if(v[k][j]==x || v[i][k]==x)
        {
            return false;
        }
    }
    if(v[3*(i/3)+(i/3)][3*(j/3)+(i%3)]==x) return false;
    return true;
}

bool Solver(vector<vector<int>>&v, int n)
{
    int i;
    int j;
    int flag=0;
    for( i=0 ;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(v[i][j]==0)
            {
                // cout<<"here1 "<<endl;
                flag=1;
                break;
            }
        }
        
        if(flag==1)
        {
            // cout<<"hi "<<i<<" "<<j<<endl;
            break;
        }
    }
    // cout<<i<<" "<<j<<endl;
    if(i==n && j==n)
    {
        // cout<<"here "<<i<<" "<<j<<endl;
        return true;
    }
    // cout<<"here "<<endl;
    for(int x=1;x<=n;x++)
    {
        if(isSafe(v,i,j,x,N))
        {
            v[i][j]=x;
            // cout<<"here"<<endl;
            if(Solver(v,n))return true;
            v[i][j]=0;
        }

    }
    return false;
}

int main()
{
    vector<vector<int>>v=
        {{3, 0, 6, 5, 0, 8, 4, 0, 0,},
{5 ,2, 0, 0, 0, 0, 0, 0, 0},
{0, 8, 7, 0, 0, 0, 0, 3, 1 },
{0, 0, 3, 0,1, 0, 0, 8, 0},
{9, 0, 0, 8, 6, 3, 0, 0, 5},
{0, 5, 0, 0, 9, 0, 6, 0, 0},
{1, 3, 0, 0, 0, 0, 2, 5, 0},
{0, 0, 0, 0, 0, 0 ,0 ,7 ,4},
{0, 0, 5, 2, 0, 6 ,3 ,0 ,0}};
    Solver(v, 9);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}




// int v[9][9]=
//         {{3, 0, 6, 5, 0, 8, 4, 0, 0,},
// {5 ,2, 0, 0, 0, 0, 0, 0, 0},
// {0, 8, 7, 0, 0, 0, 0, 3, 1 },
// {0, 0, 3, 0,1, 0, 0, 8, 0},
// {9, 0, 0, 8, 6, 3, 0, 0, 5},
// {0, 5, 0, 0, 9, 0, 6, 0, 0},
// {1, 3, 0, 0, 0, 0, 2, 5, 0},
// {0, 0, 0, 0, 0, 0 ,0 ,7 ,4},
// {0, 0, 5, 2, 0, 6 ,3 ,0 ,0}};
