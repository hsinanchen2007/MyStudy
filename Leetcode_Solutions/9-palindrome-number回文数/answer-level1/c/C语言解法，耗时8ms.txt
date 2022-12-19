### 解题思路

非常简单的思路，每次对数以10求mod, 然后得到余数乘以10加上之前的结果

最后比较下前后的结果是否一样。

要注意给定的值可能很大。

### 代码

```c
bool isPalindrome(int x){
    if ( x < 0) return false;
    if ( x >= 0 && x < 10 ) return true;
    if ( (x % 10) == 0 ) return false;

    long res = 0 ;
    int tmp = x;
    while ( x != 0){
        res = 10 * res + ( x % 10);
        x = x / 10;
    }
    if (res == tmp ) return true;
    return false;

}
```