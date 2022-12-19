执行用时 :100 ms, 在所有 C++ 提交中击败了98.42%的用户
内存消耗 :26.4 MB, 在所有 C++ 提交中击败了100.00%的用户
```
static const auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        sort(paths.begin(),paths.end());
        int big=0;
        vector<int> ans(N,1); 
        int count=0;
        while(count==0){
            count=1;
            for(int i=0;i<paths.size();i++){
                if(ans[paths[i][0]-1]==ans[paths[i][1]-1] && ans[paths[i][0]-1]<4 ){
                    ans[max(paths[i][0],paths[i][1])-1]+=1;
                    count=0;
                }
                if(ans[paths[i][0]-1]==ans[paths[i][1]-1] && ans[min(paths[i][0],paths[i][1])-1]==4 ){
                    ans[max(paths[i][0],paths[i][1])-1]=1;
                    count=0;
                }
            }
        }
        return ans;
    }
};
```

