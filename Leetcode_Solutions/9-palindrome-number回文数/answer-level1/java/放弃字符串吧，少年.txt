```
class Solution {
       public boolean isPalindrome(int x) {
        //负数和最后一位是0，且不等于0的数一定不是回文
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return Boolean.FALSE;
        }
        //当原数字小于反转后的数字时，说明已经反转了一半了
        int reverNumber = 0;
        while (x > reverNumber) {
            reverNumber = reverNumber * 10 + x % 10;
            x = x / 10;
        }
        //当前后相等，或者为奇数位，去掉中间的一位后相等，说明是回文，否则不是
        return x == reverNumber || x == reverNumber / 10;
    }
}
```
思路是反转一半的数字，再比较后一半与前一半是否相等，重点是判断何时反转到一半了：
**当原数字小于反转后的数字时说明已经到一半了**