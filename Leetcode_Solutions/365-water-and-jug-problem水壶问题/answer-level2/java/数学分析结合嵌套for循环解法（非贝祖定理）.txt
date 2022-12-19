### 解题思路
1、这道题考的是最后两个水壶一共装多少升水，那么我将两个水壶看作一个整体，不考虑水壶之间倒来倒去，就变成了倒入多少水和倒出多少水之差。

2、倒入水的单位和倒出水的单位是以两个壶分开计的，要么是一直用x壶倒入，用y壶倒出，要么是一直用y壶倒入，用x壶倒出，因为只能用整壶计量，所以每次倒入一定是满壶水，倒出也一定是满壶水。那么问题就可以简化为mx+ny=z，m和n都为整数。（如果不理解的话，也可以参考其它题解推导到这一步的过程原理）

3、到了此处最优解是用贝祖定理，只要z是x和y的最大公约数的倍数，则m和n必有整数解。但笔者所用方法与之不太一样，请继续往下看。

4、因为一个是倒出，一个是倒入，所以m和n必为一正一负，问题变为|mx-ny|=z,其中m和n都为非负整数。因为m和n都为非负整数，我就考虑是否可以利用嵌套for循环，遍历m和n的值，最终找到能使等式成立的值。此时的问题就变为找出遍历m和n的范围。

5、因为最终剩下的是两个水壶一共能装多少水，所以z的范围是0 <= z <= x+y, 即 |mx-ny| <= x+y，即
-x-y <= mx-ny <= x+y，在x不等于0的情况下，推出
```
 (n-1)*y/x - 1 <= m <= (n+1)*y/x + 1。
```
假设y>=x(作此假设是因为反过来x>=y同理能证)，则y/x>=1，即可证
``` 
n-2 <= m <= (n+1)*y/x + 1
```
此时我们拿到了内循环m的范围，接下来找出外循环n的范围即可。

6、当m=0且n=0的时候，z为0（即两个壶都空了），所以当再次遍历到mx - ny = z = 0（即两个壶都空了）时，即可认为m和n到了最大值，因为再往后，所有的z值都可以和之前重复。所以只要找到x和y的公倍数，即可得到n的最大值。此处最高效的做法应该是找出x和y的最小公倍数，再求出n的最大值，但我偷了个懒，没有写找最小公倍数的算法，直接找的是x乘y这个公倍数，即n的最大值设定为x。则外循环n的范围是  
```
0 <= n < x
```

7、最终遍历m和n的值，找到使|mx-ny|=z等式成立的值即可返回true，遍历结束未找到则返回false。

8、因为这个方法最终会有int溢出的风险，所以在循环中我将相关int数据转换成了long类型。


### 代码

```java
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        if(z > x + y) {
            return false;
        }
        if(z == x + y || z == 0) {
            return true;
        }
        if(x == 0) {
            if(z == y) {
                return true;
            } else {
                return false;
            }
        }
        if(y == 0) {
            if(z == x) {
                return true;
            } else {
                return false;
            }
        }
        int minNum = 0;
        int maxNum = 0;
        if(x >= y) {
            minNum = y;
            maxNum = x;
        } else {
            minNum = x;
            maxNum = y;
        }

        for(int n = 0; (long)n < minNum; n++) {
            for(int m = n-2; (long)m <= (n+1L)*maxNum/minNum+1L; m++) {
                if(m >= 0 && Math.abs(((long)n)*maxNum-((long)m)*minNum) == (long)z) {
                    return true;
                }
            }
        }

        return false;
    }
}
```