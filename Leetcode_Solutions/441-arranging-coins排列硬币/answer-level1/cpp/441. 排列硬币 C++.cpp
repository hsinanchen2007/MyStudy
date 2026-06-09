### 解题思路
1.使用等差数列求和公式逆向求解即可。
2.等差数列公式为 k(k + 1) / 2 = n,k 即为行数，由n反求k即可。

### 代码

```cpp
class Solution {
public:
    int arrangeCoins(int n) {
        int result = 0;
        result = sqrt(2) * sqrt(n + 0.125) - 0.5;
        return result;
    }
};
```