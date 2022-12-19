执行用时 :56 ms, 在所有C++提交中击败了81.14%的用户
内存消耗 :11.8 MB, 在所有C++提交中击败了84.24%的用户
```
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int old_r = nums.size();
        int old_c = nums[0].size();
        int new_r = 0;
        int new_c = 0;
        vector<vector<int> > res(r,vector<int>(c));
        if((old_r*old_c) != (r*c)) return nums;
        for(int i=0;i<old_r;i++){
            if(new_r == r) break;
            for(int j=0;j<old_c;j++){
                res[new_r][new_c] = nums[i][j];
                new_c+=1;
                if(new_c == c){
                    new_c = 0;
                    new_r += 1;
                }
                 
            }
        }
        return res;
    }
};
```