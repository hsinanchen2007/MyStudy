### 解题思路
1、每一行除去两边的1，其中每一个数字都是由上一行的同样地方的数字加上前一个数字得到的；
2、两层循环，暴力解法，第一层循环每一行，第二层循环得出这一行的所有数字，结束第二层循环后插入到结果数组。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<int> resultIndex;

        if(numRows == 0) return result;

        for(int i = 1; i <= numRows; i++){
            if(i != 1) resultIndex.push_back(1);
            for(int j = 2; j < i; j++) resultIndex.push_back(result[i-2][j-2]+result[i-2][j-1]);
            resultIndex.push_back(1);
            result.push_back(resultIndex);
            resultIndex.clear();
        }

        return result;
    }
};
```