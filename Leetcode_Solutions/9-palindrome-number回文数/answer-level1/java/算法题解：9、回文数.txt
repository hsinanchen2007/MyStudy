思路：比较反转前的数字和反转后数字的大小。

当然，也是有优化空间的，比如反转到一半，如果是偶数位的数字，到一半的数字就可以进行比较了；如果是奇数位的数字，那就比较一半前后的数字反转后是否相等。


```
class Solution {
    public boolean isPalindrome(int x) {
        // 如果是小于0的或者以0结尾但不等于0的数，一定不是回文数
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        // 这里的思路是记录一个起始的值，用数学方式将起始值进行反转，最后比对起始值和反转后的值
        int start = x;
        int end = 0;
        
        while (x >= 10) {
            end = end * 10 + x % 10;
            x /= 10;
        }

        // 对剩下最后一位数字的处理
        if (x < 10) {
            end = end * 10 + x % 10;
        }

        // 比对起始值和反转后的值
        if (start == end) {
            return true;
        } else {
            return false;
        }
    }
}
```
