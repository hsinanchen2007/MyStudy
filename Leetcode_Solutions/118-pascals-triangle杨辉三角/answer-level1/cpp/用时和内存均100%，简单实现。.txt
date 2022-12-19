### 解题思路
用时和内存均100%。初始化i个，不执行push_back。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> r;
        vector<int> t;
        for (int i=1;i<=numRows;i++)
        {
            vector<int> tmp(i,1);
            for (int j=1;j<i-1;j++)
            {
                tmp[j] = (t[j-1]+t[j]);
            }
            t = tmp;
            r.push_back(t);
        }

        return r;

        


    }
};
```