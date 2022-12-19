通过数学推导，可以得出题目其实等价于求m和n从高位开始，有多少位是相同的，这些相同的位组成的数就是答案，代码如下：
```
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = 0;
        int k = 1 << (sizeof(int) * 8 - 2); // 非负整数的最大二次幂
        while (k > 0 && (m & k) == (n & k)) {
            res |= k & m;
            k >>= 1;
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/1170577e27805de677d972bc51cfaa8addb6c8013e410614fae73d341b33295f-image.png)
