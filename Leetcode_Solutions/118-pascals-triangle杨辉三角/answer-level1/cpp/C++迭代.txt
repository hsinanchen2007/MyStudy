### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows==0) return res;
        res.push_back({1});
        if(numRows==1) return res;
        for(int i=1;i<numRows;++i){
            vector<int> curRow(1,1);//开头的1
            for(int j=0;j<i-1;++j){
                curRow.push_back(res[i-1][j]+res[i-1][j+1]);
            }
            curRow.push_back(1);
            res.push_back(curRow);
        }
        return res;
    }
};
```