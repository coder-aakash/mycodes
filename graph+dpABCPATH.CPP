#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define X first
#define Y second
#define LOOPI(i,a) for(int i=0;i<a;++i)
#define LOOPD(i,a) for(int i=a;i>=0;--i)
#define LOOPI1(i,a,b) for(int i=a;i<b;++i)
#define FILL(a,x) memset(a,x,sizeof(a))
#define	foreach( gg,itit )	for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
#define	mp make_pair
#define	pb push_back
#define all(s) s.begin(),s.end()
#define present(c,x) ((c).find(x) != (c).end())
using namespace std;
 int h,w;
int res=0,visit[52][52],dp[52][52];
int x[]={-1,-1,-1, 0, 1, 1, 1, 0},
    y[]={-1, 0, 1, 1, 1, 0,-1,-1};
char mat[52][52];

int  dfs(int i,int j)
{
    if(dp[i][j]!=0)
    {
      return dp[i][j];
    }
   // res=max(res,path);
   int val=1;
    for(int k=0;k<8;k++)
    {

        int i1=i+x[k];
        int j1=j+y[k];

        if(i1>=0&&i1<h&&j1>=0&&j1<w)
        {
            if((mat[i1][j1]==mat[i][j]+1 )&& visit[i1][j1]==0)
            {

              //path++; //important don't do this in recursive functions with for loops
              visit[i1][j1]=1;

              //return(dp[i][j]=max(path ,dfs(i1,j1,path+1)));//this is causing problem here
              val=max(val ,1+dfs(i1,j1));



            }
        }

    }

    return(dp[i][j]=val);

}

int main()
{


     int t=0;
    while(cin>>h && cin>>w && w!=0&& h!=0 )
    {
        res=0;
        string s;
        for(int i=0;i<h;i++)
        {
            cin>>s;
            for(int j=0;j<w;j++)
            {
                //cin>>
                mat[i][j]=s[j];
                visit[i][j]=0;
                dp[i][j]=0;
            }
        }

     int ans=0;

       for(int i=0;i<h ;i++)
       {
           for(int j=0;j<w;j++)
           {
               if(mat[i][j]=='A')
               {
                 visit[i][j]=1;
                 ans= max(ans,dfs(i,j));
               }
           }
       }
       res = ans;
      cout<<"Case "<<++t<<": "<<res<<endl;
    }

    return 0;
}
