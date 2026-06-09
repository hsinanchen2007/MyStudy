### 解题思路
性质：记一个数为i，那么对应的格雷码为 (i >> 1) ^ i
### 代码

```cpp
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        for(int i = 0;i < (1 << n);++i){
            res.push_back((i >> 1) ^ i);
        }
        return res;
    }
};
```