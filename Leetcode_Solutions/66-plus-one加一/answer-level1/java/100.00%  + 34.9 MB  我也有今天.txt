
![批注 2019-11-23 142331.png](https://pic.leetcode-cn.com/6f722159c0957e6dfa89d370cbac7a4591881a412afb98c64ae96e4760c62a13-%E6%89%B9%E6%B3%A8%202019-11-23%20142331.png)

没想到我也能超过100%，一来看大家都是  orz...

不同之处是有的用求余，有多个条件判断的

多条件判断的不说了，肯定能优化。

关于求余这种
```
            digits[i]++;
            digits[i] = digits[i] % 10;
            if (digits[i] != 0) return digits;

作者：yhhzw
链接：https://leetcode-cn.com/problems/plus-one/solution/java-shu-xue-jie-ti-by-yhhzw/
```
加法不是比算余数更快吗？虽然不快多少 hh。


```
class Solution {
    public int[] plusOne(int[] digits) {
         for (int i = digits.length - 1; i >= 0; i--) {
            if (digits[i] + 1 < 10) {
                digits[i] = digits[i] + 1;
                return digits;
            }else{
                digits[i] = 0;
            }
        }
        int[] arr = new int[digits.length + 1];
        arr[0] = 1;
        return arr;
    }
}
```
