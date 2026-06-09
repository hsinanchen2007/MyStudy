

```
class Solution {
    public int reverse(int x) {
      int temp = Math.abs(x);
      int res = 0;
      while(temp > 0) {
        if(res > Integer.MAX_VALUE / 10) return 0; //判断是否溢出
        res = res * 10 + temp % 10;
        temp /= 10;
      }

      return x > 0 ? res : -res;

    }
}
```
