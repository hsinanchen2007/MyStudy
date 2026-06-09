### 解题思路
套二分查找算法，测试用例用的数好大，所以改把数全转为long long类型。
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :8.2 MB, 在所有 C++ 提交中击败了77.50%的用户
还行！

### 代码

```cpp
class Solution {
public:
    int mySqrt(int x) {
        long long lo = 0, hi = (long long)x + 1;
        while (lo < hi) {
            long long mi = (lo + hi) >> 1;
            x < mi * mi ? hi = mi : lo = mi + 1;
        }
        return lo - 1;
    }
};
```