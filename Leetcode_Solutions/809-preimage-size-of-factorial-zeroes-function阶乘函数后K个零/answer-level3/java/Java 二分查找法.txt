### 解题思路
此题用二分查找法，利用了leetcode172	阶乘后的零

因为某个数阶乘后面的有几个零是由5的个数决定的，而每5个数就有可以让阶乘多增一个0，所以答案要么是0要么是5

用二分查找法看看能不能找到一个数他有K个0，如果能找到直接返回即可，找不到则返回0

### 代码

```java
class Solution {
    public int preimageSizeFZF(int K) {
        long left = 0;
        long right = 5L * (K + 1);
        while (left < right) {
            long mid = left + (right - left) / 2;
            int num = (int)numOfTrailingZero(mid);
            if (num == K) {
                return 5;
            } else if (num < K) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return 0;
    }

    long numOfTrailingZero(long n ) {
        int num = 0;
        while (n / 5 != 0) {
            num += n / 5;
            n = n / 5;
        }
        return num;

    }
}
```