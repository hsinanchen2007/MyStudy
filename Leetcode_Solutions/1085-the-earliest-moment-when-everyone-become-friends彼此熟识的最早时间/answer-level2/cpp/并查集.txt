```
class Solution {
public:
    int find(vector<int> & f,int x){
        while(x!=f[x]){
            x = f[x];
        }
        return x;
    }
    
    bool uni(vector<int> & f,int x,int y){
        int x1 = find(f,x);
        int y1 = find(f,y);
        if(x1 < y1){
            f[y1] = x1;
        }else{
            f[x1] = y1;
        }
        
        return true;
    }
    
    bool acuqire(vector<int> & f){
        for(int i = 0;i < f.size(); ++i){
            if(find(f,i) != 0){
                return false;
            }
        }
        
        return true;
    }
    
    static bool cmp(vector<int> & a,vector<int> & b){
        return a[0] < b[0];
    }
    
    int earliestAcq(vector<vector<int>>& logs, int N) {
        vector<int> f(N,0);
        
        /*initial*/
        sort(logs.begin(),logs.end(),cmp);
        for(int i = 0;i < N; ++i){
            f[i] = i;
        }
        
        for(int i = 0;i < logs.size(); ++i){
            uni(f,logs[i][1],logs[i][2]);
            if(acuqire(f)){
                return logs[i][0];
            }
        }
        
        return -1;
    }
};
```