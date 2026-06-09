### 解题思路
第一次双百,easy

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows, vector<int>());
        if(numRows == 0) return {};
        for(int i = 0; i <= numRows - 1; i++)
        {
            //res[i].resize(i+1);
            for(int j = 0; j<=i; j++)
            {
                if(j == 0)
                    res[i].push_back(1);
                else if(j == i)
                    res[i].push_back(1);
                else
                    res[i].push_back(res[i-1][j-1] + res[i - 1][j]);  
            }   
        }
        return res;
    }
};
```