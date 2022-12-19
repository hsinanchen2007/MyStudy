### 解题思路
 * 贪心 + 快速幂模
 * n>=5 尽可能多分割3、3。。
 * n==4 分 2 2
 * n==3 2
 * n==2 1
 * n<2 0
 * (quickPowMod(3, p3, mod) * quickPowMod(2, p2, mod))%mod)

### 代码

```java
class Solution {
    int mod = 1000000007;
    public int cuttingRope(int n) {
        if (n<2) return 2;
        if (n==2) return 1;
        if (n==3) return 2;

        int p3 = n/3;
        if (n-3*p3 == 1) {
            p3 -=1 ;// p3-1 个3 和一个4
        }
        int p2 = (n-p3*3)/2;
        return (int)((quickPowMod(3, p3, mod) * quickPowMod(2, p2, mod))%mod);
    }
    // 求解(a^b)%m
    long quickPowMod(long a, long b, int m) {
        long ans=1;   //记录结果
        a=a%m;   //预处理，使得底数a处于m的数据范围之下
        while(b!=0)
        {
            if((b&1)>0) ans=((ans%m)*a)%m;   //如果b的二进制位不是0，那么我们的结果是要参与运算的
            b>>=1;    //二进制的移位操作，相当于每次除以2，用二进制看，就是我们不断的遍历b的二进制位
            a=(a*a)%m;   //不断的加倍  log2 (a*a)^(b/2)
        }
        return ans;
    }
}
```
![image.png](https://pic.leetcode-cn.com/a4b92898a572b4cb1b240553eacad75369617a72848be922d16da72a18b8a9dd-image.png)
