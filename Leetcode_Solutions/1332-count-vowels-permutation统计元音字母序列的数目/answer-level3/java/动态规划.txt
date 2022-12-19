### 解题思路

这题是一个典型的动态规划题目：
以a结尾的长度为i+1的数量为`cnt['a'][i + 1] = cnt['b'][i] + cnt['i'][i] + cnt['u'][i]`, 同理可以得出长度为i+1的以'e', 'i', 'o', 'u'结尾的结果计算方式。这道题要注意数据类型的选用，Integer的最大值为2147483647, 3个模10^9+7的值相加可能会超过最大值。

![图片.png](https://pic.leetcode-cn.com/17443ce84f543fccc761c42714415d2a0c2515131f2f90152b772bb9856323c1-%E5%9B%BE%E7%89%87.png)

### 代码

```java
class Solution {
    public int countVowelPermutation(int n) {
        long[] cnt = new long[5];
        Arrays.fill(cnt, 1);
        long[] next = new long[5];
        for (int i = 1; i < n; i++) {
            next[0] = cnt[1] + cnt[2] + cnt[4];
            next[1] = cnt[0] + cnt[2];
            next[2] = cnt[1] + cnt[3];
            next[3] = cnt[2];
            next[4] = cnt[2] + cnt[3];
            for (int j = 0; j < next.length; j++) {
                if (next[j] >= 1000000007) {
                    next[j] = next[j] % 1000000007;
                }
            }
            System.arraycopy(next, 0, cnt, 0, 5);
        }

        int result = 0;
        for (int i = 0; i < cnt.length; i++) {
            result += cnt[i];
            result %= 1000000007;
        }
        return result;
    }
}
```