本质是A*算法，每次选取连通区域最大的外延即可，我们只在图的连通区域中的两个点一定存在相连的路径。
```
struct cmp{
    bool operator() (pair<int,int> &a , pair<int,int> & b){
        return a.first <= b.first;
    }
};

class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        int r = A.size();
        int c = A[0].size();
        int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        int res = INT_MAX;
        vector<vector<bool>> visit(100,vector<bool>(100,false));
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
        
        /*BFS*/
        pq.push(make_pair(A[0][0],0));
        visit[0][0] = true;
    
        while(!pq.empty()){
            pair<int,int> curr = pq.top();
            pq.pop();
            
            int score = curr.first;
            int x = curr.second/c;
            int y = curr.second%c;
            res = min(res,score);
            
            if(x == r-1 && y == c-1){
                return res;
            }
            
            for(int i = 0; i < 4; ++i){
                int x1 = x + d[i][0];
                int y1 = y + d[i][1];
                
                if(x1 >= 0 && x1 < r && y1 >= 0 && y1 < c){
                    if(!visit[x1][y1]){
                        pq.push(make_pair(A[x1][y1],x1*c+y1));
                        visit[x1][y1] = true;
                    }
                }
            }            
        }
        
        return -1;
    }
};
```