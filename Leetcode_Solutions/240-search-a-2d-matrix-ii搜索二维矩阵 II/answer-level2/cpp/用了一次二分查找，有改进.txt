### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0||matrix[0].size()==0)
        {
            return false;
        }
        for(int i=0;i<matrix.size();i++)
        {
            if(matrix[i][matrix[i].size()-1]<target)
            {
                continue;
            }
            int right=matrix[i].size()-1;       //右边
            int left=0;
            int mid=0;
            while(left<=right)
            {
                mid=(left+right)/2;
                if(target<matrix[i][mid])
                {
                    right=mid-1;
                }
                else if(target>matrix[i][mid])
                {
                    left=mid+1;
                }
                else
                {
                    return true;
                }
            }
        }
        return false;
    }
};
```//感觉可以用2次二分查找，一开始第二次没用二分的时候，是2000ms，用了一次变成了408ms,感觉第一个判断也可以改为二分