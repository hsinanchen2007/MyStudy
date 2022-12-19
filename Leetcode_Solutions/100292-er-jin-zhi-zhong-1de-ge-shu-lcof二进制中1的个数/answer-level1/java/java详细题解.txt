# 题解1：左移解法

使用变量i=1，让i持续左移，一直与n做与运算，如果结果不等于0则time加1。

**其实要注意的是不是结果大于0，而是结果不等于0**，因为存在负数，比如（11111111111111111111111111111101），
但我们要把它当做无符号数来处理。

```
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
       int i=1;
       int time = 1;
       int res = 0;
       while(time<=32)
       {
           //防止高位是符号位
           if((i&n)!=0)
            res++;
            i=i<<1;
           time++;
       }
       return res; 
    }
}
```
# 题解2：n&n-1
该解法的核心是减少循环的次数，尝试只循环n中1的个数次。n&n-1可以将n中最右侧的1去掉，
每一次运算后可以将当前**n最右边的1置为0**，那么我们就可以判断**当n=0时结束循环**,**这样循环的次数为n中1的个数**
        举例：
        n=  1100
        n-1=1011
        n&n-1 = 1000


```
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int times = 0;
        while(n!=0)
        {
            n = n&(n-1);
            times++;
        }
        return times;
    }
}
```
