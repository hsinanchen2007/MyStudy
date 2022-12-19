思路：
负数不是回文数直接返回false；
正数通过循环求余和乘10操作算出倒序的值后比较是否相等，若相等则为true，否则返回false；
注意：用例有超过int最大值，所以直接用的long类型绕过问题，不考虑数据类型限制，只求简单直观解法
```
bool isPalindrome(int x){
    if (x < 0) {
        return false;
    }
    long reverse = 0;
    long original = x;
    while (x != 0) {
        reverse = reverse * 10 + x % 10;
        x /= 10;
    }
    if (original == reverse) {
        return true;
    }
    return false;
}
```
