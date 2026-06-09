### 解题思路
如果数组中存在连续的 3 个 0，则表示可以种花，利用贪心算法和常数优化解决即可，非常简洁的代码。

### 代码

```cpp
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // 贪心算法 + 常数优化
        for (int i = 0; i < flowerbed.size(); i++) {
            if ((i == 0 || flowerbed[i - 1] == 0) && flowerbed[i] == 0 && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)) {
                flowerbed[i] = 1;
                n -= 1;

                if (n <= 0) return true;
            }
        }

        return n <= 0;
    }
};
```