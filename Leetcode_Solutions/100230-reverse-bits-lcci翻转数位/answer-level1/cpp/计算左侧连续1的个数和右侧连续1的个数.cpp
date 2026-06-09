基本思路：

首先计算出每一个位置左侧连续1的个数和右侧连续1的个数，然后对 num 的每一位遍历，如果当前位是 0，则反转后连续1的个数为 `left[i] + right[i] + 1`;
实际上，左侧连续1的个数不需要提前计算出，在求最终结果时动态更新即可。

```
class Solution {
   public:
    int reverseBits(int num) {
        bitset<32> bit(num);

        int right[32];
        right[31] = 0;
        for (int i = 30; i >= 0; i--) {
            if (bit[i + 1] == 1) {
                right[i] = right[i + 1] + 1;
            } else {
                right[i] = 0;
            }
        }

        int res = 0;
        if (bit[0] == 0) res = right[0] + 1;

        int left = 0;
        for (int i = 1; i < 32; i++) {
            if (bit[i - 1] == 0)
                left = 0;
            else
                left += 1;

            if (bit[i] == 0) {
                res = max(res, left + right[i] + 1);
            }
        }
        return res;
    }
};
```

时间复杂度：O(32) = O(1)
空间复杂度：O(32) = O(1)