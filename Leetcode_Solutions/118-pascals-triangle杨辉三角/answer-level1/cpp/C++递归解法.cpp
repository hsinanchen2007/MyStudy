### 解题思路
层间用了递归，一层一层叠起来

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 0)
        {
            vector<vector<int>> result;
            return result;
        }
        if(numRows == 1)
        {
            vector<vector<int>> result;
            vector<int> tmp(1,1);
            result.push_back(tmp);
            return result;
        }
        vector<vector<int>> result = generate(numRows-1);
        if(numRows != 1)
        {
            vector<int> tmp(numRows);
            tmp[0] = 1; tmp[numRows-1] = 1;
            for(int i = 1;i < numRows-1;i++)
                tmp[i] = result[numRows-2][i-1]+result[numRows-2][i];
            result.push_back(tmp);
        }
        return result;
    }
};
```