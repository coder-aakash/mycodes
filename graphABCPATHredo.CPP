#include<bits/stdc++.h>
using namespace std;


int h,w;
int res=0,visit[52][52];
int movx[]={-1,-1,-1,0,0,1,1,1}, movy[]={-1,0,1,-1,1,-1,0,1};

void dfs(char matrix[52][52],int x,int y,int path)
{
    res=max(res,path);

    for(int i=0;i<8;i++)
    {
        if(x+movx[i]>=0 && x+movx[i]<h && y+movy[i]>=0 && y+movy[i]<w && visit[x+movx[i]][y+movy[i]]==0)
        {
            if(matrix[x+movx[i]][y+movy[i]]==matrix[x][y]+1)
            {
                //cout<<"matrix( "<<x+movx[i]<<" , "<<y+movy[i]<<" ) = "<<matrix[x+movx[i]][y+movy[i]]<<"->";
                visit[x+movx[i]][y+movy[i]]=1;
                dfs(matrix,x+movx[i],y+movy[i],path+1);
            }
        }
    }
}

int main()
{
    char matrix[52][52];
    int t=0;

    while(cin>>h && cin>>w&&h>0&& w>0)
    {

        string s;
          res=0;
        for(int i=0;i<h;i++)
        {

            cin>>s;

            for(int j=0;j<s.length();j++)
            {
                matrix[i][j]=s[j];
                visit[i][j]=0;
            }
        }
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                if(matrix[i][j]=='A')
                {

                    visit[i][j]=1;
                    dfs(matrix,i,j,1);

                }
            }
        }

        cout<<"Case "<<++t<<": "<<res<<endl;
    }
    return 0;
}

