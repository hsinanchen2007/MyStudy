![image.png](https://pic.leetcode-cn.com/072a989245ef8bc0358ab16596b12319a0433123a78694d00b070a0a862cb02e-image.png)


```
class Solution {
public:
    vector<vector<int>> res;
    int size=9;
    void trace(vector<int>&path,int sum,int st,int k,int n){
        if(path.size()==k&&sum==n){
            res.push_back(path);
            return;
        }
        for(int i=st;i<=size;i++){
            if(sum+i<=n){
                path.push_back(i);
                trace(path,sum+i,i+1,k,n);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        trace(path,0,1,k,n);
        return res;
    }
};

```