我的思路很简单，**采用和十位数颠倒相同的方式即可。**

```
public class Solution {
    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        int ret = 0;
        // 32位整数，循环32次
        for (int i = 0; i < 32; i++) {
            int tmp = (n % 2 == 0) ? (0:1);     // 判断最右边【即d0位】那位是0还是1
            n = n >> 1;                         // 将原数右移
            ret = ret*2 + tmp;                  // 加乘到新数之中
        }
        
        return ret;
    }
}
```
