### 解题思路

因子分解，两个因子分布在根的一左一右。因此从根的floor值往1去遍历

### 代码

```cpp
class Solution {
public:
    vector<int> closestDivisors(int num) {
        for (int i = sqrt(num + 2) + 0.5; i >= 1; i ++) {
            if ((num + 2) % i == 0) return {i, (num + 2) / i};
            if ((num + 1) % i == 0) return {i, (num + 1) / i};
        }
        return {};
    }
};
```