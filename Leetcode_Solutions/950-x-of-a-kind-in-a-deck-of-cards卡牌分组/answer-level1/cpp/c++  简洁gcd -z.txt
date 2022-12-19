### 代码

```cpp
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int m[10000]={0};           //构造一个哈希map，统计数字出现次数
        int X = 0;
        for(int n : deck)           m[n]++;
        for(int i : m)             X = gcd(X,i);           //找到所有数字出现次数的最大公约数

        return X >= 2;
    }

};
```