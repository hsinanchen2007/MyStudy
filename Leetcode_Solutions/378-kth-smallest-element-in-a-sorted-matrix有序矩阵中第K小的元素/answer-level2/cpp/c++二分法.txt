### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size()-1;  //说了n*n矩阵
        int left=matrix[0][0];
        int right=matrix[n][n];
    
        while(left<=right)
        {
            int count=0;
            int mid=left+(right-left)/2;
            for(int i=0;i<=n;i++)
            {
                for(int j=0;j<=n&&(matrix[i][j]<=mid);j++)
                {
                        count++;
                }
            }
            if(count<k)
            {
                //说明值在右边
                left=mid+1;
            }
            else 
            {
                right=mid-1;
            }

        }
        return left;
    }
};
```感觉理解二分精髓才知道为何要这么做吧