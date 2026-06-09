执行用时 : 6 ms, 在Pairs of Songs With Total Durations Divisible by 60的Java提交中击败了81.44% 的用户

内存消耗 : 49.7 MB, 在Pairs of Songs With Total Durations Divisible by 60的Java提交中击败了64.19% 的用户

```
class Solution {
    public int numPairsDivisibleBy60(int[] time) {
        int count = 0;
        int[] index = new int[60];
        for (int n : time) {
            // 最后还要取模60，是因为(60 - n % 60)的值有可能等于60，而对于我们声明的数组来说，60已经越界了
            count += index[(60 - n % 60) % 60];
            index[n % 60]++;
        }
        return count;
    }
}
```