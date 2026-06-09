考虑到n,m很小，可以通过暴力解决
唯一不一样的是加了一个状态保存
由于n,m<=8，于是可以将棋盘的任意一个状态对应为一个long long型，将其当作key保存该状态下能够放的最多的骨牌
暴力嘛 时间空间都挺高的。。。
```cpp
class Solution {
#define ULL unsigned long long
    map<ULL,int> state;
    const int step[4][2]={0,1,0,-1,1,0,-1,0};
    
    vector<vector<int>> genmp(int n,int m,const vector<vector<int>>& b){
        vector<vector<int>> mp;
        for(int i=0;i<n;i++) mp.push_back(vector<int>(m,0));
        for(vector<int> v:b) mp[v[0]][v[1]]=1;
        return mp;
    }
    
    bool inmp(int i,int j,int n,int m){
        return i>=0&&i<n&&j>=0&&j<m;
    }
    
    ULL toull(int n,int m,vector<vector<int>>& mp){
        ULL s=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                s<<=1;
                s+=mp[i][j];
            }
        }
        return s;
    }
    
    int dfs(int i,int j,int n,int m,vector<vector<int>>& mp){
        if(!inmp(i,j,n,m))return 0;
        if(mp[i][j]==1)return 0;
        ULL st=toull(n, m,mp);
        if(state.find(st)!=state.end()) return state[st];  // state appeared before
        
        mp[i][j]=1;  //place
        int maxx=0;
        // if place domino
        for(int s=0;s<4;s++){
            int ii=i+step[s][0],jj=j+step[s][1];
            if(!inmp(ii,jj,n,m))continue;
            if(mp[ii][jj]==1)continue;//broken or already place
            
            mp[ii][jj]=1; //place
            
            int maxxx=0;
            for(int h=0;h<n;h++)
                for(int w=0;w<m;w++)
                    if(mp[h][w]==0) maxxx=max(maxxx,dfs(h,w,n,m,mp));
            
            maxx=max(maxx,1+maxxx);
            mp[ii][jj]=0; //unplace
        }
        //if not place domino
        for(int h=0;h<n;h++)
            for(int w=0;w<m;w++)
                if(mp[h][w]==0) maxx=max(maxx,dfs(h,w,n,m,mp));
        
        state[st]=maxx;  //save state
        mp[i][j]=0; //unplace
        return maxx;
    }

public:
    int domino(int n, int m, vector<vector<int>>& b) {
        vector<vector<int>> mp=genmp(n,m,b);
        int maxx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mp[i][j]==0)
                    maxx=max(maxx,dfs(i,j,n,m,mp));
            }
        }
        return maxx;
    }
};
```
