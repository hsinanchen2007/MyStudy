**方法一：转为字符串**
```
class Solution {
    /**
    * 思路：
    * (1) 将整数转为字符串然后反转和原字符串比较。
    * (2) 如果相同则原整数为回文数，否则不是。
    */
    public boolean isPalindrome(int x) {
        String reversedStr = (new StringBuilder(x + "")).reverse().toString();
        return (x + "").equals(reversedStr);
    }
}
```

**方法二：反转整数**
```
class Solution {
    /**
    * 思路：
    * (1) 由题先判断一定是回文数和一定不是回文数的整数区间。
    * (2) 然后将整数反转和原整数比较是否相等，如果相等则是回文数，否则不是。
    */
    public boolean isPalindrome(int x) {
		// 如果x为0到9的个位数则肯定是回文数。
        if (x >= 0 && x < 10){
            return true;
		// 另外如果x为负数或者结尾为0则一定不是回文数。
        }else if (x < 0 || x % 10 == 0){
            return false;
        }
        int curr = x;
        int rev = 0;
        while (curr != 0){
            // 因为输入为整数类型，反转以后越界则一定不是回文数
            if (rev * 10 / 10 != rev){
                return false;
            }
            rev = rev * 10 + curr % 10;
            curr /= 10;
        }
        return rev == x;
    }
}
```

**方法三：反转整数优化**
```
class Solution {
    /**
    * 思路：
    * 反转输入整数的一半和剩余一半比较。
    */
    public boolean isPalindrome(int x) {
        if (x >= 0 && x < 10){
            return true;
        }else if (x < 0 || x % 10 == 0){
            return false;
        }
        int rev = 0;
        // 直到反转部分不小于剩余部分，则表示反转了原整数长度的一半
        while (x > rev) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        // 如果输入整数长度为奇数，则反转部分长度比剩余部分长一位。
        return x == rev || x == rev / 10;
    }
}
```
