# 思路
首先确定N的值。易知：`nums.length + 2`就是N。

接下来：**nums数组的数** 和 **1-N的数** 一同**构成的集合**  特征为——该集合内只有2个数字出现过1次，而其余数字都出现2次，请找出这2个只出现1次的数字。

有这样的思维转变的话，相信你已经知道怎么做了。
如果不知道，请先看[另一题](https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/solution/3chong-fang-fa-by-gfu/)

# 代码
```java
class Solution {
    public int[] missingTwo(int[] nums) {
        int N = nums.length + 2;
        int xor = 0, idx = 0;
        for (int num : nums) {
            xor ^= num;
            xor ^= ++idx;
        }
        xor ^= ++idx;
        xor ^= ++idx;
        int diff = xor & (-xor);
        int x = 0;
        idx = 0;
        for (int num : nums) {
            if ((diff & num) != 0)
                x ^= num;
            if ((diff & ++idx) != 0)
                x ^= idx;
        }
        if ((diff & ++idx) != 0)
            x ^= idx;
        if ((diff & ++idx) != 0)
            x ^= idx;
        return new int[]{x, xor ^ x};
    }
}
```
