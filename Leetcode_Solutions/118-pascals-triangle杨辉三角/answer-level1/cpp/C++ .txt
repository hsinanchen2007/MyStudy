### 解题思路
做这题以前 我没搞懂dp到底是什么 写完ac后 问了人 才知道我这也是dp 凉了

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows==0) return res;
        for(int i = 1;i<=numRows;i++)
        {
            vector<int> temp(i,0);
            for(int j = 0;j<i;j++)
            {
                if(j==0||j==(i-1))
                {
                    temp[j] = 1;
                }
                else
                {
                    temp[j] = res[i-2][j-1]+res[i-2][j];
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};
```