### 解题思路
根据排列组合公式推导出每行i+1位和i位的关系。这里有两个注意点：1.到第30行int会溢出，需要中间转long计算完再转回int；2.每行只需计算前一半。刚开始学c++，代码风格可能不是很c++ style。

### 代码

```cpp
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res = {1};
        for (int i = 1; i <= rowIndex; i++){
            if (i <= (rowIndex/2)) {
                long cur = res[i-1]*((rowIndex-i+1)/i);
                res.push_back((int)((long)res[i-1]*(long)(rowIndex-i+1)/(long)i));
            } else
                res.push_back(res[rowIndex-i]);
        }
        return res;
    }
};
```