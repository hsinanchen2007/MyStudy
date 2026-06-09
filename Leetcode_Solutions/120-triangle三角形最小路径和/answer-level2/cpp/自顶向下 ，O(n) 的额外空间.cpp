### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row=triangle.size();
        if(row==1)return triangle[0][0];
        vector<int> sum(row,INT_MAX);
        sum[row-2]=triangle[0][0]+triangle[1][0];
        sum[row-1]=triangle[0][0]+triangle[1][1];
        if(row==2)return min(sum[0],sum[1]);
        for(int i =2;i<row;i++){
            for (int j=0;j<i+1;j++){
                if (j==i)
                    sum[row-1]=sum[row-1]+triangle[i][j];
                else
                    sum[row-i-1+j]=min(sum[row-i-1+j],sum[row-i+j])+triangle[i][j];
            }
        }
        int mi=sum[0];
        for(auto n:sum)
        {
            mi=min(mi,n);
        }
        return mi;
    }
};
```