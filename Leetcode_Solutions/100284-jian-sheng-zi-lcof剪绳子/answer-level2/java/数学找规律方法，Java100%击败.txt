![1.png](https://pic.leetcode-cn.com/329195647eb9fca4fc7b411d0b7c08a6219251a6d883311af3879af5ab138f14-1.png)


### 解题思路
被除数是n，除数为2，得到结果a1。如果有余数（除数是2，那么余数为1）则添加到a1上，得到a1+1，累乘的结果为a1(a1+1)。
被除数是n，除数为3，得到结果a2。如果有余数（除数是3，假设余数为2）则添加到a2上，得到a2+1，累乘的结果为a2(a2+1)(a2+1)。
                              如果有余数（除数是3，假设余数为1）则添加到a2上，得到a2+1，累乘的结果为a2*a2(a2+1)。
以此类推，可以发现当除数递增，累乘的结果先递增后递减，在中间获得最大值。
那么用prev和curr记录除数递增前和递增后的累乘结果，当累乘结果出现下降，则先前的累乘结果即为最大值。

### 代码

```java
class Solution {
    public static int cuttingRope(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 1;
        if (n == 3) return 2;

        int prev = 0;
        int curr = 0;
        for (int i = 2; i <= n/2; i++) {
            int divide = n/i;
            int left = n%i;
            curr = 1;
            for (int j = 0; j < i-left; j++) {
                curr *= divide;
            }
            for (int j = 0; j < left; j++) {
                curr *= (divide+1);
            }
            if (curr < prev) return prev;
            prev = curr;
        }

        return curr;
    }
}
```