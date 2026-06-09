### 解题思路
使用两个数组，一个记录上一行结果即可

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows==0)
            return res;
        vector<int> x;
        x.push_back(1);
        res.push_back(x);
        for(int i=2;i<=numRows;i++){
            vector<int> y;
            y.push_back(1);
            for(int j=0;j<x.size()-1;j++)
                y.push_back(x[j]+x[j+1]);
            y.push_back(1);
            res.push_back(y);
            x=y;
        }
        return res;
    }
};
```