![image.png](https://pic.leetcode-cn.com/9df2fb306b3da268ff8a5013eca3b649ca659f5d83b03a790a4d26e6d75431ae-image.png)

### 解题思路
遇到 0 的时候，将上一个 0 左右两边连续 1 的个数相加，再加 1，就可以得到一个备选的答案，备选答案中的最大值即为最终的答案。

len : 上一个 0 左边连续 1 的个数
count : 上一个 0 右边连续 1 的个数
ans : 之前备选的答案中的最大值

### 代码

```cpp
class Solution {
public:
    int reverseBits(int num) {

        int ans = 0;
        int count = 0;
        int len = 0;

        while(num) {
            if (num % 2 == 1) {
                count++;
            } else {
                ans = max(ans, (count + len + 1));
                len = count;
                count = 0;
            }

            num >>= 1;
        }

        return max(ans, (count + len + 1));
    }
};
```