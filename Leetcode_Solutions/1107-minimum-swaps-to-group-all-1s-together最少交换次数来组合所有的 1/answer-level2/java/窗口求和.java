先记录起始到每个点的总和，窗口大小为1的总个数，窗口右端总和减去左端总和就是窗口内1的个数。取最大

```java
class Solution {
    public int minSwaps(int[] data) {
        int[] sums = new int[data.length + 1];
        int sum = 0;
        sums[0] = 0;
        for (int i = 1; i <= data.length; i++) {
            sum += data[i - 1];
            sums[i] = sum;
        }

        int k = sums[data.length];

        int maxOnes = 0;

        for (int i = 1, j = i + k - 1; i <= data.length && j <= data.length; i++, j++) {
            int ones = sums[j] - sums[i - 1];
            if (ones > maxOnes) {
                maxOnes = ones;
            }
        }

        return k - maxOnes;
    }
}
```