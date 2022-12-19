## 计算出每一个数的行和列，直接插入新矩阵
```cpp
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int r0=nums.size(), c0=nums[0].size();
        if(r0*c0 != r*c) return nums;
        vector<vector<int>> ans(r, vector<int>(c));
        int no=0, no_i=0, no_j=0;
        for(int i=0; i<r0; i++){
            for(int j=0; j<c0; j++){
                no_i = no/c; //计算行
                no_j = no%c; //计算列
                ans[no_i][no_j] = nums[i][j];
                no++;
            }
        }
        return ans;
    }
};
```