参考楼下的解法，代码如下：
```

class Solution {
public:
    int find(vector<int> & f,int x){
        while(f[x] != x){
            x = f[x];
        }
        return x;
    }
    bool uni(vector<int> &f,int x,int y){
        int x1 = find(f,x);
        int y1 = find(f,y);
        f[x1] = y1;
        return true;
    }
    int regionsBySlashes(vector<string> &grid) {
        int n = grid.size();
        int length = n*n*4;
        vector<int> f(length,0);
        set<int> count;
        /*initail*/
        for(int i = 0;i < length; ++i){ f[i] = i;}
        
        for(int i = 0;i < n; ++i){/*merge*/
            for(int j = 0;j < n; ++j){
                int idx = (i*n + j)*4;
                if(grid[i][j] == '/'){
                    uni(f,idx,idx+1);
                    uni(f,idx+2,idx+3);
                }else if(grid[i][j] == '\\'){
                    uni(f,idx+1,idx+2);
                    uni(f,idx,idx+3);
                }else if(grid[i][j] == ' '){
                    uni(f,idx,idx+1);
                    uni(f,idx+1,idx+2);
                    uni(f,idx+2,idx+3);
                }
                if(i > 0){ uni(f,idx-4*n+3,idx+1);}
                if(j > 0){ uni(f,idx-2,idx);}
            }
        }
        for(int i = 0;i < length; ++i){
            count.insert(find(f,i));
        }
        return count.size();
    }
};


```