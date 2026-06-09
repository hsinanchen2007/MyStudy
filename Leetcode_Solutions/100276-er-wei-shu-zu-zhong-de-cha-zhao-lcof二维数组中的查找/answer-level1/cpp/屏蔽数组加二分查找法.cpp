### 解题思路
此处撰写解题思路
解题的时候没有太好的思路。
现在的做法是：
首先屏蔽掉matrix[i][0]比target大的数组
然后在matrix[i][0]比target小的数组中，屏蔽掉matrix[i][matrix[i].size()-1] 比target小的数组
最后在剩下的数组中每一个使用二分查找法求解。
当然在屏蔽掉数组的时候判断下边界值是否和target相等。
时间复杂度貌似有点高，应该有更好的屏蔽方法。

### 代码

```cpp
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int MatrixLen = matrix.size();
        if(MatrixLen == 0) return false;

        for(int i=0;i<MatrixLen;i++)
        {
            if(matrix[i].size() == 0) continue;

            if(matrix[i][0] < target)
            {
                int SMatrixLen = matrix[i].size();
                if(matrix[i][SMatrixLen-1] < target)
                {
                    continue;
                }else if(matrix[i][SMatrixLen-1] == target)
                {
                    return true;
                }else
                {
                    // 每一条数据中使用二分查找法
                    if(IsNumInVecArray(matrix[i],target))
                    {
                        return true;
                    }else
                    {
                        continue;
                    }
                }
            }else if(matrix[i][0] == target)
            {
                return true;
            }else if(matrix[i][0] > target)
            {
                return false;
            }
        }

        return false;
    }

    bool IsNumInVecArray(const vector<int>& VecNums,const int& target)
    {
        int LeftIndex = 0;
        int RightIndex = VecNums.size();
        int MiddleIndex = RightIndex / 2;

        while(LeftIndex <= RightIndex)
        {
            if(VecNums[MiddleIndex] < target)
            {
                LeftIndex = MiddleIndex + 1;
            }else if (VecNums[MiddleIndex] > target)
            {
                RightIndex = MiddleIndex - 1;
            }else if(VecNums[MiddleIndex] == target)
            {
                return true;
            }

            MiddleIndex = (LeftIndex + RightIndex) / 2 ;
        }

        return false;
    }
};
```