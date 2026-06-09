**为武汉加油**，各种dfs，写+改用了几小时才AC

要处理的细节较多
总体来说

1. `dfs`找到最危险的区域`(x,y)`，其中`(x,y)`为最危险区域中的任意一点
2. 从`(x,y)`所属区域`dfs`开始模拟造墙
3. 造完墙后，从`(x,y)`开始`dfs`封锁这片造完墙的区域
4. 封锁后，`dfs`模拟扩散过程
- 直到找不到`(x,y)`，或者造完墙后的地图与扩散病毒后的地图一样时结束
```cpp
class Solution {
    int M,N;
    vector<vector<int>> mp;
    int vis[105][105];
    int step[4][2]={-1,0,1,0,0,-1,0,1};//l,r,t,b
    
    struct pos{
        int x,y;
    };
    
    bool ingrid(int i,int j){
        return i<M&&i>=0&&j<N&&j>=0;
    }

    /**
    void print(vector<vector<int>>& mp){
        for(int i=0;i<mp.size();i++){
            for(int j=0;j<mp[0].size();j++)
                if(mp[i][j]==-1)printf("%2c ",'*');
                else if(mp[i][j]==-2)printf("%2c ",'+');
                else printf("%2d ",mp[i][j]);
            cout<<endl;
        }
        cout<<endl;
    }
    **/

    int sum(const vector<vector<int>>& grid){
        int cnt=0;
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                cnt+=grid[i][j];
            }
        }
        return cnt;
    }
    
    void spread(vector<vector<int>>& mp){
        memset(vis, 0, sizeof(vis));
        vector<vector<int>> tmp;
        vector<vector<int>> tmpmp;
        tmpmp.assign(mp.begin(), mp.end());
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(i%2||j%2)continue;
                if(!vis[i][j]&&mp[i][j]==1){
                    tmp.assign(mp.begin(), mp.end());
                    dfs(mp, tmp, i, j);
                    
                    for(int i=0;i<M;i++){//copy vir
                        for(int j=0;j<N;j++){
                            if(tmp[i][j]==1&&tmpmp[i][j]!=tmp[i][j])tmpmp[i][j]=tmp[i][j];
                        }
                    }//copy done
                    
                }
            }
        }
        mp.assign(tmpmp.begin(), tmpmp.end());
    }
    
    void dfs(const vector<vector<int>>& mp,vector<vector<int>>& tmp,int i,int j){
        vis[i][j]=1;
        for(int s=0;s<4;s++){
            int iw=i+step[s][0],jw=j+step[s][1];
            if(ingrid(iw, jw)&&mp[iw][jw]==-2)continue;//is wall
            
            int ii=i+step[s][0]*2,jj=j+step[s][1]*2;// go
            if(!ingrid(ii, jj))continue;
            
            if(mp[ii][jj]==0){ // is clean, spread
                tmp[ii][jj]=1;
            }else if(mp[ii][jj]==1&&!vis[ii][jj]){ //is vir, dfs
                dfs(mp, tmp, ii, jj);
            }
            
        }
    }
    
    
    pos findmaxdanger(const vector<vector<int>>& mp){
        vector<vector<int>> tmp;
        
        memset(vis, 0, sizeof(vis));
        int maxn=0;
        int sumgrid=sum(mp);
        pos p;
        p.x=999;
        p.y=999;
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(i%2||j%2)continue;//wall
                if(!vis[i][j]&&mp[i][j]==1){
                    tmp.assign(mp.begin(), mp.end());
                    dfs(mp,tmp,i,j);
                    
                    int sumtmp=sum(tmp);
                    if(sumtmp-sumgrid>maxn){
                        maxn=sumtmp-sumgrid;
                        p.x=i;
                        p.y=j;
                    }
                }
            }
        }
        return p;
    }
    
    void dfsforbuildwall(vector<vector<int>>& mp,int i,int j){
        // make sure mp[i,j] is point, neither street nor wall
        vis[i][j]=1;
        for(int s=0;s<4;s++){
            int iw=i+step[s][0],jw=j+step[s][1];
            if(ingrid(iw, jw)&&mp[iw][jw]==-2)continue;//is wall
            
            int ii=i+step[s][0]*2,jj=j+step[s][1]*2;// go
            if(!ingrid(ii, jj))continue;

            if(vis[ii][jj]&&mp[ii][jj]==1)continue;
            
            if(mp[ii][jj]==0){//need build wall
                mp[iw][jw]=-2;
            }else if(mp[ii][jj]==1){//need dfs
                dfsforbuildwall(mp, ii, jj);
            }
        }
    }
    
    void buildwall(vector<vector<int>>& mp,int i,int j){
        memset(vis, 0, sizeof(vis));
        dfsforbuildwall(mp,i,j);
    }
    
    void blockarea(vector<vector<int>>& mp,int i,int j){// make block val=2
        mp[i][j]=2;
        for(int s=0;s<4;s++){
            int iw=i+step[s][0],jw=j+step[s][1];
            if(ingrid(iw, jw)&&mp[iw][jw]==-2)continue;//is wall
            
            int ii=i+step[s][0]*2,jj=j+step[s][1]*2;// go
            if(!ingrid(ii, jj))continue;
            
            if(mp[ii][jj]==1)blockarea(mp, ii, jj);
        }
    }
    
public:
    int containVirus(vector<vector<int>>& grid) {
        
        for(int i=0;i<grid.size();i++){
            
            if(i){
                vector<int> tmpp;
                for(int j=0;j<grid[0].size();j++){
                    if(j)tmpp.push_back(-1);
                    tmpp.push_back(-1);
                }
                mp.push_back(tmpp);
            }
            
            vector<int> tmp;
            for(int j=0;j<grid[0].size();j++){
                if(j)tmp.push_back(-1);// for street -1,and for wall -2
                tmp.push_back(grid[i][j]);// for clean 0, and for vir 1, and for block 2
            } 
            mp.push_back(tmp);
        }
        print(mp);
        
        M=mp.size();
        N=mp[0].size();
        
        while (true) {//one day
            pos p=findmaxdanger(mp);
            if(p.x>=M||p.y>=N)break;
            
            buildwall(mp, p.x, p.y);
            // cout<<"after build wall"<<endl;
            // print(mp);
            
            blockarea(mp, p.x, p.y);
            int sumblockarea=sum(mp);
            // cout<<"after block area"<<endl;
            // print(mp);
            
            spread(mp);
            int sumspread=sum(mp);
            // cout<<"after spread vir"<<endl;
            // print(mp);
            
            if(sumspread-sumblockarea==0)break;
            // cout<<"one day gone"<<endl;
            
        }
        
        int summ=0;
        for(int i=0;i<M;i++)
            for(int j=0;j<N;j++)
                if((i%2||j%2)&&mp[i][j]==-2)summ++;
            
        // cout<<"the len of wall = "<<summ<<endl;

        return summ;
    }
};
```

```yaml
# 过程图示，其中
# -2表示墙（+）
# -1表示过道（*，忽略交叉点的*，其实是没有的）
# 0表示未被感染区域
# 1表示未被封锁的病毒
# 2表示已被封锁的病毒区域
start
 1  *  1  *  1  *  0  *  0  *  0  *  0  *  0  *  0 
 *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  * 
 1  *  0  *  1  *  0  *  1  *  1  *  1  *  1  *  1 
 *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  * 
 1  *  1  *  1  *  0  *  0  *  0  *  0  *  0  *  0 

after build wall
 1  *  1  *  1  *  0  *  0  *  0  *  0  *  0  *  0 
 *  *  *  *  *  *  *  *  +  *  +  *  +  *  +  *  + 
 1  *  0  *  1  *  0  +  1  *  1  *  1  *  1  *  1 
 *  *  *  *  *  *  *  *  +  *  +  *  +  *  +  *  + 
 1  *  1  *  1  *  0  *  0  *  0  *  0  *  0  *  0 

after block area
 1  *  1  *  1  *  0  *  0  *  0  *  0  *  0  *  0 
 *  *  *  *  *  *  *  *  +  *  +  *  +  *  +  *  + 
 1  *  0  *  1  *  0  +  2  *  2  *  2  *  2  *  2 
 *  *  *  *  *  *  *  *  +  *  +  *  +  *  +  *  + 
 1  *  1  *  1  *  0  *  0  *  0  *  0  *  0  *  0 

after spread vir
 1  *  1  *  1  *  1  *  0  *  0  *  0  *  0  *  0 
 *  *  *  *  *  *  *  *  +  *  +  *  +  *  +  *  + 
 1  *  1  *  1  *  1  +  2  *  2  *  2  *  2  *  2 
 *  *  *  *  *  *  *  *  +  *  +  *  +  *  +  *  + 
 1  *  1  *  1  *  1  *  0  *  0  *  0  *  0  *  0 

one day gone
after build wall
 1  *  1  *  1  *  1  +  0  *  0  *  0  *  0  *  0 
 *  *  *  *  *  *  *  *  +  *  +  *  +  *  +  *  + 
 1  *  1  *  1  *  1  +  2  *  2  *  2  *  2  *  2 
 *  *  *  *  *  *  *  *  +  *  +  *  +  *  +  *  + 
 1  *  1  *  1  *  1  +  0  *  0  *  0  *  0  *  0 

after block area
 2  *  2  *  2  *  2  +  0  *  0  *  0  *  0  *  0 
 *  *  *  *  *  *  *  *  +  *  +  *  +  *  +  *  + 
 2  *  2  *  2  *  2  +  2  *  2  *  2  *  2  *  2 
 *  *  *  *  *  *  *  *  +  *  +  *  +  *  +  *  + 
 2  *  2  *  2  *  2  +  0  *  0  *  0  *  0  *  0 

after spread vir
 2  *  2  *  2  *  2  +  0  *  0  *  0  *  0  *  0 
 *  *  *  *  *  *  *  *  +  *  +  *  +  *  +  *  + 
 2  *  2  *  2  *  2  +  2  *  2  *  2  *  2  *  2 
 *  *  *  *  *  *  *  *  +  *  +  *  +  *  +  *  + 
 2  *  2  *  2  *  2  +  0  *  0  *  0  *  0  *  0 

the len of wall = 13
```