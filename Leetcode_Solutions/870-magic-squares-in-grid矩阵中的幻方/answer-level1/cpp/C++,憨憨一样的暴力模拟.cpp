#### 思路：按照题目要求进行判断。。。。没什么好说的
```
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int res=0;
        int n=grid.size();
        int m=grid[0].size();
        if(n<3||m<3)return 0;
        int cnt,num,temp,ans1,ans2;
        bool flag;
        for(int i=0;i+3<=n;i++){
            for(int j=0;j+3<=m;j++){
                temp=-1,ans1=0,ans2=0;
                for(int k=0;k<3;k++){
                    ans1+=grid[i+k][j+k];
                    ans2+=grid[i+2-k][j+k];
                }
                //cout<<ans1<<" "<<ans2<<endl;
                if(ans1!=ans2)continue;
                flag=false;
                vector<int>vis(20,0);
                for(int k=0;k<3;k++){
                    for(int t=0;t<3;t++){
                        vis[grid[i+k][j+t]]=1;
                    }
                }
                bool tag=false;
                for(int i=1;i<=9;i++){
                    if(vis[i]==0){
                        tag=true;
                        break;
                    }
                }
                if(tag)continue;
                for(int k=0;k<3;k++){
                    cnt=0,num=0;
                    for(int t=0;t<3;t++){
                        if(k+i<n&&t+j<m){
                            cnt+=grid[k+i][t+j];
                        }
                        if(t+i<n&&k+j<m){
                            num+=grid[t+i][k+j];
                        }
                        
                    }
                    //cout<<cnt<<" "<<num<<endl;
                    if(temp==-1)temp=cnt;
                    if(cnt!=num||cnt!=temp){
                        flag=true;
                        break;
                    }
                }
                //cout<<cnt<<" "<<ans1<<endl;
                //cout<<flag<<endl;
                if(!flag&&cnt==ans1)res++;
            }
        }
        return res;
    }
};
```