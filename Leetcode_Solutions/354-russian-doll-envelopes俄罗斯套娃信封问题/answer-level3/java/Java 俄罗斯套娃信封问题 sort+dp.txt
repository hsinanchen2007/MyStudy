一开始: 硬套就完事了嗷
单纯用了sort+贪心, 发现贪心的局部最优并不能解决问题于是想到了dp

接下来是步骤 (思路
[5,4],[6,4],[6,7],[2,3] 排序 => [2,3],[5,4],[6,4],[6,7]

因为在不能套其他信的情况下, 答案是1 所以初始化dp为1
初始化dp => dp = [1,1,1,1]
两个循环
外循环是遍历信封 => a
内循环是遍历之前的信封 => b
当b可以装下a的时候 使用状态转移方程dp[i] = max(dp[i], dp[j] + 1)
用a套所有可以套的b, 而这个b在之前已经套了所有可能套的信封, 并且将最大值存在dp中, 所以可以得出a所能套的最多信封的个数
因为保证了每一步是最优的 所以dp[i]一定是这个信封的最大值
最后输出dp中最大的数字

```
class Solution {
    boolean compare(int[] o1, int[] o2) {
        if(o1[0] < o2[0] && o1[1] < o2[1]) return true;
        return false;
    }

    public int maxEnvelopes(int[][] envelopes) {
        Arrays.sort(envelopes, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if(o1[0] == o2[0]) return o1[1] - o2[1];
                return o1[0] - o2[0];
            }
        });
        int res = 0;
        int[] dp = new int[envelopes.length];
        for(int i = 0; i < envelopes.length; i ++) {
            int[] currEnvelope = envelopes[i];
            dp[i] = 1;
            for(int j = i; j >= 0; j --) {
                if(compare(envelopes[j], currEnvelope)) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
        }
        for(int num: dp) {
            res = Math.max(num, res);
        }
        return res;
    }
}
```

😄业余题解