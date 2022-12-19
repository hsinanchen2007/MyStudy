### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int row=nums.size();
        int col=nums[0].size();
        if(r*c!=row*col)
        {
            return nums;
        }
        vector<vector<int>>res(r,vector<int>(c));
        int sum=0;
        int reshape_row=0;
        int reshape_col=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                reshape_row=sum/c;  //对应行
                reshape_col=sum%c;  //对应列
                res[reshape_row][reshape_col]=nums[i][j];
                sum++;
            }
            
        }
        return res;
    }
};
```//重点在于行列的选取