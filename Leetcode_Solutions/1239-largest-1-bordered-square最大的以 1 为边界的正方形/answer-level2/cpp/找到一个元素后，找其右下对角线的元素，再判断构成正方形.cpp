    class Solution {
    public:
        int largest1BorderedSquare(vector<vector<int>>& grid) {
            int i=0,j=0,a,b,k,l,a1,b1,a2,b2;    //注意不同层次的循环采用不同变量
            int res=0;
            bool flag;  //构成正方形
            while(i<grid.size())
            {
                if(grid[i][j]==1)
                {
                    a1=i,b1=j;
                    a=i,b=j;
                    if(res==0)res=1;  
                    while((a<grid.size()-1)&&(b<grid[0].size()-1))  //找正方形对角线
                    {
                        a++,b++;
                        if(grid[a][b]==1)
                        {
                            a2=a,b2=b;
                            flag=true;
                            //四边上的情况
                            for(k=a1;k<a2;k++)
                                if((grid[k][b1]==0||grid[k][b2]==0)&&flag)
                                    {flag=false;break;}
                            for(l=b1;l<b2;l++)
                                if((grid[a1][l]==0||grid[a2][l]==0)&&flag)
                                    {flag=false;break;}
                            if(flag)res=max(res,(a2-a1+1)*(a2-a1+1));
                        }
                    }
                }
                j++;
                if(j==grid[0].size()){i++,j=0;}
            }
        
            return res;
        }
    };