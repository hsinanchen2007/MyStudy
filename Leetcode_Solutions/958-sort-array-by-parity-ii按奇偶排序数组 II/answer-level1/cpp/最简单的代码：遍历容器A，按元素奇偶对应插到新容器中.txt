```
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int size = A.size(), i = 0, j = 1;
        vector<int> ans(size);
        for(auto &w : A){
            if (w % 2 == 0){
                ans[i] = w;
                i += 2;
            }
            else{
                ans[j] = w;
                j += 2;
            }
        }
        return ans;
    }
};
```
