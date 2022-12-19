java解法，32位数如果是4的幂，那么只有奇数位有且只有一个1，偶数位都是0。判断条件为与0xaaaaaaaa做与运算结果为0。（a=1010）
```
class Solution {
    public boolean isPowerOfFour(int num) {
        if((num & 0xaaaaaaaa)==0 &&Integer.bitCount(num)==1) return true;
        else return false;
    }
}
```
