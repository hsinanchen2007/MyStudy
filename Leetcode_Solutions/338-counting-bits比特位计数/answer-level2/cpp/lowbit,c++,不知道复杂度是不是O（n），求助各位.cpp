想知道lowbit算法的复杂度是不是O（1），我用lowbit+dp做的。请各位指点。
```
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num+1);
        ans[0] = 0;
        for(int i = 1 ; i <= num ; i++){
            ans[i] = ans[i-(i&(-i))]+1;
        }
        return ans;
    }
};
```
