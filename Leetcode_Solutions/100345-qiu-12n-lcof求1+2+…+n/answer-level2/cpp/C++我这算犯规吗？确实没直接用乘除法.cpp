### 解题思路
不知道pow和移位操作算不算犯规

### 代码

```cpp
class Solution {
public:
    int sumNums(int n) {
        return (n + (int)pow(n, 2)) >> 1;
    }
};
```