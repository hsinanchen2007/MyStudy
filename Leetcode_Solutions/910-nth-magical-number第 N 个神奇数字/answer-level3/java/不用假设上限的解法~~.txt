### 解题思路
很多题解都是在一个很大范围内二分查找，这个解法有点过于依赖数值范围。
也都提到了最大公约数和最小公倍数。

有了最小公倍数后，其实这个题目是有周期的，可以利用最大公倍数求出周期，然后把N化小。
最后可以在0到最小公倍数的范围二分查找即可。
假如最大公倍数为 beishu，
那么周期为period =  beishu / A + beishu / B - 1
例如 4 和 6，最大公约数为 12。
周期 = 12 / 4 + 12 / 6 - 1 = 4，意思是4个数字一轮循环。
4 6 8 12   16 18 20 24   28 30 32 36
第一轮      第二轮        第三轮
有了这个假设，就可以只用在 N % period 求解了。
算法用时 0ms，不知道是不是系统出了bug，试了4-5次，都是0ms~~~


### 代码

```java
class Solution {
    private int gcd(int a, int b) {
        if (b % a == 0) {
            return a;
        }
        return gcd(b % a, a);
    }

    int getCountsByNum(int count, int A, int B) {
        return count / A + count / B;
    }

    int midSearch(int A, int B, int counts, int beishu) {
        int left = 0;
        int right = beishu;
        while (left < right) {
            int mid = (left + right) / 2;
            int midCount = getCountsByNum(mid, A, B);
            if (midCount < counts) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    public int nthMagicalNumber(int N, int A, int B) {
        int small = Math.min(A, B);
        int big = Math.max(A, B);

        int yueshu = gcd(small, big);
        int beishu = small * big / yueshu;

        int period = (beishu / A) + (beishu / B) - 1;
        long times = N / period;
        int counts = N % period;
        long mod = 1000000007;
        int midCount = midSearch(small, big, counts, beishu);
        long result = (times * beishu) % mod;
        result = (result + midCount) % mod;
        return (int) result;
    }
    
}
```