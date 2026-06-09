// ### 解题思路
// ![image.png](https://pic.leetcode-cn.com/74b3bc1aa4c16734ad550c954a8c5be1804c1892d18c4f284ce5c645c1492e40-image.png)

// 主要就是result的类型先设置大一点（long long），之后再根据结构调整输出。

// 直接看代码吧👇

// ### 代码

// ```cpp
class Solution {
public:
    int reverse(int x) {
        long long result = 0;
        while (x) {
            result = 10 * result + x % 10;
            x /= 10;
        }
        if (result >= INT_MAX || result < INT_MIN) {
            return 0;
        }
        else return result;
    }
};
// ```