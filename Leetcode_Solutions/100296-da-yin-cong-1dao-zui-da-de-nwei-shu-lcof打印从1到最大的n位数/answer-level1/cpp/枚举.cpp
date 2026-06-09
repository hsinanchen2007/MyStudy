### 解题思路
枚举

### 代码

```cpp
class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int>t;
        long long m=pow(10,n);
        for(int i=1;i<m;i++)
            t.push_back(i);
        return t;
    }
};
```