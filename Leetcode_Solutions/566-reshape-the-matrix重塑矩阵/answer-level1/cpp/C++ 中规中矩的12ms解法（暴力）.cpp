```cpp
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int n = nums.size();
        int m = nums[0].size();
        if (n * m != r * c) return nums;

        int ro = 0, co = 0;
        vector<vector<int>> res(r, vector<int>(c));
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                res[i][j] = nums[ro][co];
                ++co;

                if (co == m){
                    ++ro;
                    co = 0;
                }
            }
        }
        return res;
    }
};
```