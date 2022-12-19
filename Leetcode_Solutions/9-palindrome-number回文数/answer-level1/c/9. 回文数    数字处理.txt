### 解题思路
1: 非负个位数一定是回文数
2：负数 或者个位为0的多位数一定不是回文数
3: 用**long型**计算从右往左的数，进行比较

_____________________________________________________
执行用时 8 ms, 在所有 c 提交中击败了93.57%的用户
内存消耗 :7.1 MB, 在所有 c 提交中击败了90.41%的用户
### 代码

```c
bool isPalindrome(int x){
    if (x >= 0 && x/10 == 0)
        return true;
    if (x < 0 || x%10 == 0)
        return false;
    long rev = 0, copyx = x;
    while (x) {
        rev = rev*10 + x%10;
        x/=10;
    }
    if (rev == copyx) return true;
    return false;
}
```