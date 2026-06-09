```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int max = (1<<n);
        vector<vector<int>> res;
        int m=0;
        while (m<max){
            vector<int> v;
            for (int i=0; i<n; i++){
                if ((m>>i)&1){
                    v.emplace_back(nums[i]);
                }
            }
            res.emplace_back(v);
            m++;
        }
        return res;
    }
};
```