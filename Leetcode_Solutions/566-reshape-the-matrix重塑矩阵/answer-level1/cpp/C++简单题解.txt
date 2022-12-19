![image.png](https://pic.leetcode-cn.com/f2ca473d4d1c67761454260faa7a029920ee7142c745f0e6f8769d9055221f22-image.png)
解题思路：直接复制，对原数组的元素个数计数，sum/c表示行数，sum%c表示列数。
```
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if(nums.size()*nums[0].size() != r*c) return nums;
        vector<vector<int>> res(r, vector<int>(c));
        int sum=0, resi=0, resj=0;
        for(int i=0; i<nums.size(); ++i){
            for(int j=0; j<nums[0].size(); ++j){
                resi = sum/c;
                resj = sum%c;
                res[resi][resj] = nums[i][j];
            sum++;
            }
        }
        return res;
    }
```

