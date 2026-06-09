### 解题思路
顺着题目所写的即可……

### 代码

```cpp
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m=matrix.size();
        if(m==0)return res;
        int n=matrix[0].size();
        if(n==0)return res;
        res.reserve(m*n);
        int mn=m+n-1;
        int m1=m-1;
        int n1=n-1;
        for(int sum=0;sum<mn;++sum)
        {
            int h=min(m1,sum);
            int l=max(0,sum-n1);
            if(sum%2==0)
            {
                for(int i=h;i>=l;--i)
                {
                    res.push_back(matrix[i][sum-i]);
                }
            }
            else
            {
                for(int i=l;i<=h;++i)
                {
                    res.push_back(matrix[i][sum-i]);
                }
            }
        }
        return res;
    }
};
```