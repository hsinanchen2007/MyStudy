### 解题思路
动态规划

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>res;
        for(int i=0;i!=numRows;i++)
        {
            vector<int>res0(i+1,0);
            for(int j=0;j<=i;j++)
            {
                if(j!=0&&j!=i)
                    res0[j]=res[i-1][j-1]+res[i-1][j];
                res0[0]=1;
                res0[i]=1;
            }
            res.push_back(res0);
        }
        return(res);
    }
};
```