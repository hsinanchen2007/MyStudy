### 解题思路
思路：让除数来逼近被除数。
按照这个思路，自然就会想要得到两个值，就设为pre，cur，即取值区间为[pre,cur];
然后使用二分查找，不断缩减区间范围，最终找到答案。

这个思路是挺简单的，但是这个题目限制使用乘除法和mod运算符，那么怎么才能逼近被除数呢。
1. 加法。
2. 移位操作。（移位操作应该不算是乘法除法吧¬_¬）
加法比移位慢，当然选移位。

那么问题又来了，被除数和除数的正负号不一致的话，移位就没有效果了，他们只会越来越远~
所以要统一符号，那就统一为负号吧，因为负数的区间比正数的大。

emmm实际操作了下，又有几个很显然的问题：
1. 被除数太大了（指绝对值），比如-2^31，我怎么才能找到比它大的值。(这个题目好像还限制了使用int型(⊙﹏⊙))
2. 除数在左移的时候，一不小心它越界了，就是超出了负数的区间，就会变成正数或0

针对这个问题，我想到的一个方法就是把被除数分一半，即被除数向右移一位，这样就肯定能找出区间了。
但是这个情况下，就要考虑最后的余数和是否大于除数，可能对结果会有1的差别。

这边我解释下为什么只会有1的差别 (我一开始还以为需要把余数的和再来一遍全流程的QAQ)？
```
设被除数为a，除数为b。
a = a >> 1;
余数 c = a%b, 0<= c < b;
最后的余数和为 d = 2*c + 1 (此处a为奇数，为奇数时d的值能达到最大)
此时 d的最大值为 2*(b-1)+1 = 2*b -1;
2*b-1 /b 的商最大为1，故只会有1的区别。
```
最后，ans = (divident >> 1) /divisor,  ans = ans <<1, ans += 余数和部分的商，判断下dividend和divisor的符号是否一致，
一致直接返回ans，不一致返回-ans。

### 废话
emm代码写到最后的时候，总感觉写的像**一样，逻辑不够清晰，痛苦不能一个享受(～￣▽￣)～，请君欣赏下这个毒代码，顺便有啥不对的一定要告诉我，感谢你的阅读~
哦，这个代码提交竟然还只要1ms，amazing！

### 代码

```java
class Solution {
    public int divide(int dividend, int divisor) {
        //如果除数为1，返回被除数
        if (divisor == 1) return dividend;
        //特判溢出的情况
        if (dividend == Integer.MIN_VALUE && divisor == -1) return Integer.MAX_VALUE;
        //如果除数为-1，返回被除数的相反数
        if (divisor == -1) return -dividend;

        boolean sign = false,odd = false;//sign 符号位，true为两数符号不一致；odd 奇偶性，true为奇数
        if (dividend > 0 && divisor < 0 || dividend < 0 && divisor > 0) sign = true;
        // 将除数和被除数都变为负数
        dividend = dividend > 0 ? -dividend : dividend;
        divisor = divisor > 0 ? -divisor : divisor;
        // 如果除数小于被除数，那说明商为0
        if (divisor < dividend) return 0;
        // 如果商为1的情况，其中divisor+divisor > 0 表明溢出了，说明两倍的divisor一定小于-2^31
        if (divisor == dividend || divisor+divisor < dividend || divisor+divisor > 0) return sign ? -1 : 1;
        // 判断奇偶
        int temp = -dividend & 1;
        if (temp == 1) {
            odd = true;
            dividend ++;
        }
        temp = divisor;
        int ans,pre = -1,cur = 1;// pre为区间的左边界，cur为右边界

        dividend = dividend >> 1;// 除2
        // 确定右边界
        while (divisor > dividend) {
            pre = cur;
            cur = cur << 1;
            divisor = divisor << 1;
        }
        int preValue = divisor >> 1;
        int mid,midValue,diff;
        // 二分查找
        while (true) {
            // 如果左边界的值与被除数相等 或者 右边界与左边界相差1时，此时左边界就是结果
            if (preValue == dividend || cur-pre == 1) {
                ans = pre;
                diff = dividend - preValue;// 保存下余数
                break;
            }
            // 右边界的值与被除数相等
            if (divisor == dividend) {
                ans = cur;
                diff = dividend - divisor;
                break;
            }
            //取中值
            mid = pre + ((cur - pre) >> 1);
            midValue = preValue + ((divisor-preValue) >> 1);
            if (midValue >= dividend) {
                pre = mid;
                preValue = midValue;
            }
            else {
                cur = mid;
                divisor = midValue;
            }
        }
        diff <<= 1;// 余数乘2
        ans <<= 1;
        if (odd) diff--;
        if (diff < temp) ans++;
        if (sign) return -ans;
        return ans;
    }
}
```