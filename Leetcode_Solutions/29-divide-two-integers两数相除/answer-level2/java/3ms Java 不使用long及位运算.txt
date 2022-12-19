首先要明确正负数除法的规则，经过实验可得Java的规则是使得到的商尽可能接近0(即直接省去得到的负数商的小数部分)，说明商与除数的乘积的绝对值小于等于被除数的绝对值，在这个基础上实现除法的算法。

最直接的做法是让被除数挨个减去(若正负数除法则为加上)除数，复杂度为O(N)但在商的绝对值很大的情况下会超时。

更高效方法的大致方向是：将除数和被除数都化为绝对值后，倍增除数，找到比被除数小的那个值，记录倍增的次数n，2^n即是所求的商，复杂度为O(logN)。(当然具体实现更加复杂)

因为题目要求环境只能存储int范围的值，所以不使用long，也不使用与乘除相似的位运算，具体操作直接看代码。

```java
class Solution {
    public int divide(int dividend, int divisor) {
        // 只有这一种情况会造成商溢出，先处理掉
        if (dividend == Integer.MIN_VALUE && divisor == -1) {
            return Integer.MAX_VALUE;
        }

        // 记录商的正负值
        boolean isMinus = ((dividend < 0) != (divisor < 0));
        
        // 如果除数或被除数中有一个是Integer.MIN_VALUE，那么取绝对值就会溢出
        // 所以全部转化为负数进行处理
        dividend = dividend > 0 ? -dividend : dividend;
        divisor = divisor > 0 ? -divisor : divisor;
		
        // 如果被除数已经比除数大(因为全是负数)，商只可能为0
        if (dividend > divisor) {
            return 0;
        }

        int quotient = 1;		// 商的绝对值
        int d = divisor;		// 当前需要在除数上累加的值
        int sum = divisor;		// 累加后的除数
        int count = 1;			// 当前累加值对应的divisor个数，d = count * divisor

        while (true) {
            // 当累加后的除数绝对值仍小于等于被除数时，则进行累加
            // sum + d < 0 的判断是为了防止sum+d后溢出
            if (sum + d < 0 && sum + d >= dividend) {
                sum += d;				// 将待加值累加到除数上
                d += d;					// 待加值自我累加
                quotient += count;		// 更新商
                count += count;			
            } else {
                // 当且仅当加上待加值后的除数绝对值大于被除数，且待加值正好为最原始除数时才跳出
                // 因为这时累加后的除数已经达到小于等于被除数的最大值，多加一个除数都不行
                if (d == divisor) {
                    break;		
                } else {
                    // 重置待加值，以尽可能使累加除数的绝对值接近被除数
                    d = divisor;
                    count = 1;
                }
            }
        }
		
        // 最后注意商的正负号
        return isMinus ? -quotient : quotient;
    }
}
```
