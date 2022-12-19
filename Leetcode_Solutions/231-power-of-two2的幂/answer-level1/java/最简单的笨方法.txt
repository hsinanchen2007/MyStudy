执行用时 :2 ms, 在所有 Java 提交中击败了98.26%的用户
内存消耗 :34.3 MB, 在所有 Java 提交中击败了11.82%的用户

思路：
①若n == 0，则直接跳过循环返回false；
②若n == 1，则返回true；
③若n>1的整数，一直除以则最后n会等于0或者1；同时，在n=1之前，每次循环都对2取余，只要余数是1的则不是2的幂。

```
class Solution {
    public boolean isPowerOfTwo(int n) {
        while (n != 0) {
            if (n == 1 && n % 2 == 1) return true;
            else if (n % 2 == 1) return false;
            n /= 2;
        }
        return false;
    }
}
```
