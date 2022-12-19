### 解题思路
其实这个题目就是来求最大公约数，详细思路见注释吧！

### 思路一

```cpp
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        /*
        思路一：
            1. 若 X 能将原数组正确分组，则原数组大小一定是 X 的倍数，即 X 是原数组的公约数
            2. 如果要求每组都有相同的 X 张牌，则相同牌的数量一定要能被 X 整除，即 X 也是相同牌的数量的公约数
                例如 [1, 1, 1, 2, 2, 3, 3] ，假设 X = 2，因为有 3 个 1，所以只能分为 [1, 1]，[1]，也就不能满足条件了。
                如果是 [1, 1, 2, 2, 3, 3]，假设 X = 2，因为每个相同元素都有 2 个，都能被 X 整除，所以能够正确分组：[1, 1]，[2, 2]，[3, 3]
        */

        // 1. 求数组中每个相同元素出现的次数
        int count[1000] = { 0 };
        for (auto n : deck) count[n]++;

        int N = deck.size();
        bool flag = false;

        for (int x = 2; x <= N; x++) {
            // 2. 判断 x 是否为数组大小的公约数
            if (N % x == 0) {
                flag = true;

                // 3. 判断 x 是否为每个元素的数量的公约数
                for (auto c : count) {
                    
                    // 4. 如果当前 x 不为每个元素数量的公约数，就跳出循环，继续遍历下一个 x
                    if (c % x != 0) {
                        flag = false;
                        break;
                    }
                }

                // 5. 如果 x 既是数组大小的公约数又是每个元素数量的公约数，则 x 符合条件
                if (flag)
                    return true;
            }
        }
        return false;
    }
};
```

## 思路二
```cpp
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        /*
        思路二：在思路一的基础上，我们可以进一步优化思路
            1. 如果 x 是每个相同元素数量的公约数，那么肯定也是数组大小的公约数
            2. 所以我们只需要先求出每个元素的数量，然后计算所有相同元素数量的最大公约数 g
            3. 如果 g >= 2，返回 true。
        */

        // 1. 计算相同元素数量
        int count[10000] = { 0 };
        for (auto n : deck) count[n]++;
        
        // 初始 g = 0，因为一个数跟 0 的最大公约数为自身
        int g = 0;
        for (auto c : count) {
            if (c == 0) continue;
            
            // 2. 计算每个相同元素数量的最大公约数
            g = gcd(c, g);

            if (g == 1) return false;
        }

        return g >= 2;
    }

    // 求 x 和 y 的最大公约数
    int gcd(int x, int y) {
        return x == 0 ? y : gcd(y % x, x);
    }
};
```