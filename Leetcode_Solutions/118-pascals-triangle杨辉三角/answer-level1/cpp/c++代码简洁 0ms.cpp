
### 代码

```cpp

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 0) return {};
        vector<vector<int>>rs;
        for (int i = 0; i < numRows; i++) {
            //仔细看图 每一行 第一个 最后一个 都是1 
            //所以初始化都为1 然后遍历的时候避开这2个，可以避免一些判断
            vector<int>vec(i+1,1);
            for (int j = 1; j < i; j++) {
                vec[j] = rs[i-1][j-1] + rs[i-1][j];
            }
            rs.push_back(vec);
        }
        return rs;
    }
};
```