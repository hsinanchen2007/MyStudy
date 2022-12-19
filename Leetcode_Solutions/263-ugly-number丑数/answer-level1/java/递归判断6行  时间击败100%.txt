- 当前数为0或1时直接返回结果，其它数时就逐渐分解因数
- 当数为2,3,5其中一个数的倍数时,就除以这个对应数得到因数，直到结果为1代表为丑数，否则为非丑数
```
class Solution {
    public boolean isUgly(int num) {
        if (num == 0) return false;
        if (num == 1) return true;
        if (num % 2 == 0) return isUgly(num / 2);
        if (num % 3 == 0) return isUgly(num / 3);
        if (num % 5 == 0) return isUgly(num / 5); 
        return false;
    }
}
```
