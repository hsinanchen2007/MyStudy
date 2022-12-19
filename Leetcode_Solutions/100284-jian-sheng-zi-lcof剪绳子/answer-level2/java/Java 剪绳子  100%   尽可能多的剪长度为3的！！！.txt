### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    // 方法二：找规律解决。
    // 当n>=5时，尽可能的剪成都为3的绳子，当剩下的绳子长度为4的时候，把绳子剪为两个长度为2的绳子。
    public int cuttingRope(int n) {
        if (n <= 1) {
            return 0;
        }
        if (n == 2) {
            return 1;
        }
        if (n == 3) {
            return 2;
        }

        // 计算能剪出多少个长度为3的段
        int timesOf3 = n / 3;
        if (n % 3 == 0) {
            return (int)Math.pow(3, timesOf3);
        }
        if (n % 3 == 1) {
            // 以7为例：timesOf3 * 3 + 1 = (timesOf3 - 1) * 3 + 4
            return (int)Math.pow(3, timesOf3 - 1) * 4;
        }
        return (int)Math.pow(3, timesOf3) * 2;
    }

    // 方法一：通过前面的数据结果进行计算
    public int cuttingRope_(int n) {
        if (n <= 1) {
            return 0;
        }
        if (n == 2) {
            return 1;
        }
        if (n == 3) {
            return 2;
        }

        // results初始化的前面4个元素为后续计算的基础，绳子长度（即下标）对应的值初始化为长度值即可。
        int[] results = new int[n + 1];
        results[0] = 0;
        results[1] = 1;
        results[2] = 2;
        results[3] = 3;
        // 后续长度的计算，在此基础上计算index长度的绳子如何分割乘积最大，乘积结果为index对应的value
        for (int i = 4; i <= n; i++) {
            int max = 0;
            for (int j = 1; j <= i / 2; j++) {
                int tmp = results[j] * results[i - j];
                if (max < tmp) {
                    max = tmp;
                }
            }
            results[i] = max;
        }
        return results[n];
    }
}
```