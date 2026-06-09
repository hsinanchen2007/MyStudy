### 解题思路
1. 题目中给定的数组是n*m，可知在遍历二维数组之前，是已知数组大小；
2. 通过已知二维数组大小，寻找与给定值相等的数；
3. 按照规律每行/每列元素大小不断增加，首列元素（a[n][0]）如果已经大于查找值，那么后面元素一定大与该值，无需再查找。
注意：关键还是学习如何遍历vector二维数组。
### 代码

```cpp
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) 
    {
        if (matrix.empty())
        {
            return false;
        }
        for (int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[0].size(); j++)
            {   
                if(matrix[i][0] > target)
                {
                    return false;
                }
                if(matrix[i][j]==target)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
```