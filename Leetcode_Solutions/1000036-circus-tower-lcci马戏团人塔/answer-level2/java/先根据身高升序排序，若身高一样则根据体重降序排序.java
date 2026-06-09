# 思路
先根据**身高**  **升序排序**，若身高一样则根据**体重**  **降序排序**。
身高排序好之后，剩余待处理的就是体重。
处理体重的问题就是处理[最长递增子序列](https://leetcode-cn.com/problems/longest-increasing-subsequence/)的问题。

# PS: 
题目要求是“矮一点 且 轻一点”，是严格要求`<`而不是`<=`。

[官方测试用例](https://leetcode-cn.com/submissions/detail/47937341/testcase/)

自己可以用来小测的测试用例(答案为3而不是5)：
```
[1, 2, 2, 2, 3]
[4, 5, 6, 7, 8]
```

# 更新
在题友的提醒下，其实只需要在 **身高相同**时，**体重**按 **降序** 排序，再用二分法处理体重即可。
那么自己仔细想想为什么身高相同时，体重降序排序就可以AC；而身高相同时，体重升序排序就不能AC呢？

其实很简单的道理，将**身高相同**的人看成1个集合，若他们都按照**体重升序**来排序，则之后的二分法处理中，**有一定的概率**会在这集合中取 **>= 2 个人**作为最终结果。
为什么说是“**有一定的概率**会在这集合中取 **>= 2 个人**作为最终结果”呢？
比如: 
身高:`[1, 2, 2, 3, 4]`
体重:`[1, 3, 4, 5, 7]`
显然，在身高升序排序，且身高相同则体重升序排序的预处理后，对体重进行二分查找得到的最长递增子序列的结果是`[1, 3, 4, 5, 7]`，而体重为3、4的那2个人身高相同，不符合题意。
比如: 
身高:`[1, 2, 2, 3, 4]`
体重:`[4, 1, 2, 5, 7]`
显然，在身高升序排序，且身高相同则体重升序排序的预处理后，对体重进行二分查找得到的最长递增子序列的结果是`[4, 5, 7]`，这其中并没有包含身高为2的那2个人。(简单说就是运气好罢了，结果刚好符合题意)。


因为是**体重升序**，二分法处理时(从左往右遍历)，身高相同的人的集合 **自己本身**也**有可能**构成上升子序列，就使得最终答案内可能包含 身高相同，体重递增的结果。



同样，将**身高相同**的人看成1个集合，若他们都按照**体重降序**来排序，在二分法顺序遍历的过程中，是**无法**在这个集合中取 **>= 2个人**作为最终结果(即，要么取只能取1人，要么不取)。
因为是**体重降序**，二分法处理时(从左往右遍历)，身高相同的人的集合 **自己本身**是**无法构成**上升子序列，也就**不会出现**最终答案内包含 身高相同，体重递增的情况。

# 3种写法:
```java [-二分查找法(AC)]
class Solution {
    public int bestSeqAtIndex(int[] height, int[] weight) {
        int len = height.length;
        int[][] person = new int[len][2];
        for (int i = 0; i < len; ++i)
            person[i] = new int[]{height[i], weight[i]};
        Arrays.sort(person, (a, b) -> a[0] == b[0] ? b[1] - a[1] : a[0] - b[0]);
        int[] dp = new int[len];
        int res = 0;
        for (int[] pair : person) {
            int i = Arrays.binarySearch(dp, 0, res, pair[1]);
            if (i < 0)
                i = -(i + 1);
            dp[i] = pair[1];
            if (i == res)
                ++res;
        }
        return res;
    }
}
```
```java [-记忆+DFS(超时/超内存)]
class Solution {
    private int[][] person, memo;
    private int len;

    public int bestSeqAtIndex(int[] height, int[] weight) {
        len = height.length;
        person = new int[len][2];
        for (int i = 0; i < len; ++i)
            person[i] = new int[]{height[i], weight[i]};

        Arrays.sort(person, (a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
        memo = new int[len + 1][len];
        for (int[] l : memo)
            Arrays.fill(l, -1);
        return dfs(-1, 0, 0, 0);
    }

    private int dfs(int pre_idx, int cur_idx, int weight_bound, int height_bound) {
        if (cur_idx == len)
            return 0;

        if (memo[pre_idx + 1][cur_idx] >= 0)
            return memo[pre_idx + 1][cur_idx];

        int taken = 0;
        if (pre_idx < 0 || (person[cur_idx][1] > weight_bound && person[cur_idx][0] > height_bound))
            taken = 1 + dfs(cur_idx, cur_idx + 1, person[cur_idx][1], person[cur_idx][0]);
        int not_taken = dfs(pre_idx, cur_idx + 1, weight_bound, height_bound);
        return memo[pre_idx + 1][cur_idx] = Math.max(taken, not_taken);
    }
}
```
```java [-动态规划(超时)]
class Solution {
    public int bestSeqAtIndex(int[] height, int[] weight) {
        int len = height.length;
        int[][] person = new int[len][2];
        for (int i = 0; i < len; ++i)
            person[i] = new int[]{height[i], weight[i]};

        Arrays.sort(person, (a, b) -> a[0] == b[0] ? b[1] - a[1] : a[0] - b[0]);
        int[] dp = new int[len];
        dp[0] = 1;
        int res = 1;
        for (int i = 1; i < len; ++i) {
            int max_val = 0, base_weight = person[i][1];
            for (int j = 0; j < i; ++j)
                if (base_weight > person[j][1])
                    max_val = Math.max(max_val, dp[j]);
            dp[i] = max_val + 1;
            res = Math.max(res, dp[i]);
        }
        return res;
    }
}
```