### 解题思路

![image.png](https://pic.leetcode-cn.com/65a082194115f712cab19552f346e5a58c30266bfcc045a5ebc5b2ab316aec47-image.png)

### 代码

```cpp
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        if(n==0) return false;
        int m=matrix[0].size();
        
        int len=min(n,m);
        int x=len;
        for(int i=0;i<len;i++)
        {
            if(matrix[i][i]==target) return true;
            else if(matrix[i][i]>target)
            {
                x=i;
                break;
            }
            
        }
        for(int i=x;i<n;i++)
        {
            for(int j=0;j<x;j++)
            {
                if(matrix[i][j]==target) return true;
            }
        }
        for(int i=0;i<x;i++)
        {
            for(int j=x;j<m;j++)
            {
                if(matrix[i][j]==target) return true;
            }
        }
        return false;
    }
};
```