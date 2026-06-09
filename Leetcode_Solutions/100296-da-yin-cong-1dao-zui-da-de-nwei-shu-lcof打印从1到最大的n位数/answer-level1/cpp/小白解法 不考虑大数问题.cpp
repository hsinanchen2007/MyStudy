### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> res;
        if(n == 0) return res;
        for(int i = 1; i < pow(10,n); i++)
        {
            res.push_back(i);
        }
        return res;
    }
};
```