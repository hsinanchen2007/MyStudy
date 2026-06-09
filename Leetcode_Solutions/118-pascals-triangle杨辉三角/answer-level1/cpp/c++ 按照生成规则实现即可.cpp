### 解题思路
1. 规则即temp[j] = result[i-1][j-1] +  result[i-1][j]
需要考虑下边界值即可；

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        //直接生成即可
        vector<vector<int>> result;
        if(0==numRows) return result;
        result.push_back({1});
        for(int i=1; i<numRows; i++){
            vector<int> temp(i+1);
            temp[0] = 1;
            temp[i] = 1;
            for(int j=1; j<(i+2)/2; j++){
                temp[j] = result[i-1][j-1] +  result[i-1][j];
                temp[i-j] = temp[j];
            }
            result.push_back(temp);
        }
        return result;
    }
};
```