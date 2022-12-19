```
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> log(R,vector<int>(C,0));
        queue<pair<int,int>> q;
        q.push({r0,c0});
        log[r0][c0]=1;
        vector<vector<int>> ans;
        while(!q.empty()){
            pair<int,int> ptemp;
            int size=q.size();
            for(int i=0;i<size;++i){
                ptemp=q.front();
                q.pop();
                ans.push_back({ptemp.first,ptemp.second});
                if(lalala(R,C,ptemp.first+1,ptemp.second,log)){
                    q.push({ptemp.first+1,ptemp.second});
                    log[ptemp.first+1][ptemp.second]=1;
                }
                if(lalala(R,C,ptemp.first-1,ptemp.second,log)){
                    q.push({ptemp.first-1,ptemp.second});
                    log[ptemp.first-1][ptemp.second]=1;
                }
                if(lalala(R,C,ptemp.first,ptemp.second+1,log)){
                    q.push({ptemp.first,ptemp.second+1});
                    log[ptemp.first][ptemp.second+1]=1;
                }
                if(lalala(R,C,ptemp.first,ptemp.second-1,log)){
                    q.push({ptemp.first,ptemp.second-1});
                    log[ptemp.first][ptemp.second-1]=1;
                }
            }
        }
        return ans;
    }

    inline bool lalala(int R,int C,int x,int y,const vector<vector<int>>& log){
        if(x<0||x>=R||y<0||y>=C||log[x][y]==1){
            return false;
        }
        return true;
    }
};
```
