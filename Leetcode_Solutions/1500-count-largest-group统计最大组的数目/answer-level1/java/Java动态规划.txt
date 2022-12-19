### 解题思路
先计算从1到n的每个整数的数位和，我们用一个大小为n + 1的数组记录已经计算过的数字的数位和。

显然, sum[i] = sum[i / 10] + i % 10。在计算的同时我们统计数位和的频率。最终，返回数字数目并列最多的组。

### 代码

```java
class Solution {
    public int countLargestGroup(int n) {
        int result = 0, max = 0;
        int sum[] = new int[n + 1];
        int freq[] = new int[40];
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i / 10] + i % 10;
            freq[sum[i]]++;
        }
        for (int i = 0; i < freq.length; i++) {
            if (freq[i] > max) {
                max = freq[i];
                result = 1;
            }
            else if (freq[i] == max) {
                result++;
            }
        }
        return result;
    }
}
```