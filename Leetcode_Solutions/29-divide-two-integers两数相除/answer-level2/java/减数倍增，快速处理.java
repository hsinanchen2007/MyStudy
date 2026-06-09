### 解题思路
1，暴力法
最简单采用暴力法，为了防止溢出，全转为负数，用dividend一直减divisor。但是如此的话，由于每次只减一个，如果dividend过大，divisor过小，计算次数过多，就会超时。
那么，能不能每次多减点数呢？
2，减数倍增法
第一次计算时我们减去一个divisor，第二次计算时我们减去两个divisor，第三次减去四个divisor。。。以此类推，那么减去的次数就会剧烈的下降，从O(n)->O(log2(n)).当dividend处于(divisor,0]的区间表明计算合法且完成（因为为了防止溢出，将dividend和divisor都变成了负数），应该停止计算。
![image.png](https://pic.leetcode-cn.com/0202a6e66b3f01a251384e84aa96f98807805c869e12cf5a601f1a4347f0e21d-image.png)

但是，比如dividend=-9，divisor=-2，
    第一次：-9-（-2）->-7,减数倍增,变为-4
    第二次: -7-(-4)->-3,减数倍增,变为-8
    第三次: -3-(-8)->5,此时显然已经减多了
怎么处理? 
我们可以每次做了减法操作后(dividend减去n个divisor，n是任意的)，判断dividend是否在合法的区间(divisor,0],如果不在，则不作减，并从减去一个divisor再开始,进行倍增减法运算
    
### 代码

```java
class Solution {
public int divide(int dividend, int divisor) {

        return divide0(dividend, divisor);
    }

    //0, 加法运算
    public int divide0(int dividend, int divisor) {

        boolean isNag = true;
        if((dividend>0&&divisor>0)||(dividend<0&&divisor<0)) isNag = false;
        //全转为负数，防止溢出
        if (dividend > 0) {

            dividend = -dividend;
        }
        if (divisor > 0) {

            divisor = -divisor;
        }

        int base = 1;//表示当前减数，相对于divisor的倍数
        int nag = divisor;//当前减数
        long shang = 0;//用long存储，防止商溢出
        while (dividend>0||dividend<=divisor) {

            if(dividend<=divisor) {

                dividend -= nag;
                if(dividend>0) {

                    dividend +=nag;
                    base = 1;
                    nag = divisor;
                }
                else{
                    shang += base;
                    base = base+base;
                    nag +=nag;
                    //判断商是否越界
                    if(!isNag&&shang>Integer.MAX_VALUE) return Integer.MAX_VALUE;
                    else if(isNag&&-shang<Integer.MIN_VALUE) return Integer.MIN_VALUE;
                }
            }
        }

        return (int) (isNag?-shang:shang);
    }
}
```