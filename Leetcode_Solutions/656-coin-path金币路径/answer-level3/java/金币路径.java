#### 方法一：暴力解法【超出时间限制】

本方法中使用两个长度为 $n$ 的数组 $next$ 和 $nums$，其中 $n$ 是 $A$ 的长度，$nums[i]$ 表示从 $i$ 跳到终点的最小花费。

将数组 $next$ 的所有位置初始化为 -1，然后递归调用 `jump(A, B, i, next)` 从后向前计算数组 $next$，其中 $A$ 是金币数组，$B$ 是最大跳跃距离。

在位置 $i$ 处，可以跳跃到从 $i+1$ 到 $i+B$ 之间的任意一个位置上。假设跳跃到了 $j$ 处，那么从 $i$ 到终点的花费为 $A[i] + jump(A, B, j, next)$，如果此花费小于当前的最小花费，则更新 $next[i]=A[i] + jump(A, B, j, next)$。

每次调用方法 `jump` 都会返回从 $i$ 跳跃到终点的最小花费。

数组 $next$ 存储了最小花费的跳跃方式，从位置 1 开始遍历 $next$。在每一步，都把当前位置添加到 $res$，然后找到下一跳的位置 $next[i]$，直到数组末尾。

```java [solution1-Java]
public class Solution {
    public List < Integer > cheapestJump(int[] A, int B) {
        int[] next = new int[A.length];
        Arrays.fill(next, -1);
        jump(A, B, 0, next);
        List < Integer > res = new ArrayList();
        int i;
        for (i = 0; i < A.length && next[i] > 0; i = next[i])
            res.add(i + 1);
        if (i == A.length - 1 && A[i]>= 0)
            res.add(A.length);
        else
            return new ArrayList < Integer > ();
        return res;
    }
    public long jump(int[] A, int B, int i, int[] next) {
        if (i == A.length - 1 && A[i] >= 0)
            return A[i];
        long min_cost = Integer.MAX_VALUE;
        for (int j = i + 1; j <= i + B && j < A.length; j++) {
            if (A[j] >= 0) {
                long cost = A[i] + jump(A, B, j, next);
                if (cost < min_cost) {
                    min_cost = cost;
                    next[i] = j;
                }
            }
        }
        return min_cost;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(B^n)$，其中 $B$ 是最大跳跃距离，$n$ 是数组 $A$ 的长度。最坏情况下，每一跳都有 $B$ 种可能性，递归树的最大深度为 $O(B^n)$。

* 空间复杂度：$O(n)$。每次递归调用深度最大为 $n$，数组 $next$ 的长度为 $n$。


#### 方法二：带记忆的递归【通过】

**算法**

在 *方法一* 的递归中，一种跳跃方式被多次计算，因此存在大量重复调用。为了消除这些冗余调用，记录每次调用的返回值。

创建数组 $memo$，$memo[i]$ 记录从 $i$ 跳跃到末尾的最小花费。把每次调用的结果都保存在 $memo$ 中，下次调用相同的方法时，直接从 $memo$ 中返回结果。这种方法很大程度上减少了重复调用问题。

```java [solution2-Java]
public class Solution {
    public List < Integer > cheapestJump(int[] A, int B) {
        int[] next = new int[A.length];
        Arrays.fill(next, -1);
        long[] memo = new long[A.length];
        jump(A, B, 0, next, memo);
        List < Integer > res = new ArrayList();
        int i;
        for (i = 0; i < A.length && next[i] > 0; i = next[i])
            res.add(i + 1);
        if (i == A.length - 1 && A[i] >= 0)
            res.add(A.length);
        else
            return new ArrayList < Integer > ();
        return res;
    }
    public long jump(int[] A, int B, int i, int[] next, long[] memo) {
        if (memo[i] > 0)
            return memo[i];
        if (i == A.length - 1 && A[i] >= 0)
            return A[i];
        long min_cost = Integer.MAX_VALUE;
        for (int j = i + 1; j <= i + B && j < A.length; j++) {
            if (A[j] >= 0) {
                long cost = A[i] + jump(A, B, j, next, memo);
                if (cost < min_cost) {
                    min_cost = cost;
                    next[i] = j;
                }
            }
        }
        memo[i] = min_cost;
        return min_cost;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(nB)$，其中 $n$ 是数组 $A$ 的长度。计算长度为 $n$ 的数组 $memo$，遍历数组 $next$。

* 空间复杂度：$O(n)$。递归调用的最大深度为 $n$，数组 $next$ 的大小为 $n$。 


#### 方法三：动态规划【通过】

**算法**

从前两种方法可以看出，从位置 $i$ 跳跃数组 $A$ 末尾的花费只与 $i$ 后面的元素相关，因此可以使用动态规划解决此问题。

创建数组 $next$ 记录下一跳的位置，数组 $dp$ 记录最小花费，$dp[i]$ 表示从位置 $i$ 跳跃到末尾的最小花费。从最后一个位置开始，向前计算数组 $next$ 和 $dp$。

在位置 $i$ 处，下一跳可能的位置是从 $i+1$ 到 $i+B$ 中任意一个。假设下一跳为 $j$ 时，从 $i$ 跳跃到终点的花费最小，此时更新 $next[i]=j$，$dp[i]=A[i]+dp[j]$，并将当前结果用于之后的计算中。

最后，根据数组 $next$ 找出最小花费的路径并返回。

```java [solution3-Java]
public class Solution {
    public List < Integer > cheapestJump(int[] A, int B) {
        int[] next = new int[A.length];
        long[] dp = new long[A.length];
        Arrays.fill(next, -1);
        List < Integer > res = new ArrayList();
        for (int i = A.length - 2; i >= 0; i--) {
            long min_cost = Integer.MAX_VALUE;
            for (int j = i + 1; j <= i + B && j < A.length; j++) {
                if (A[j] >= 0) {
                    long cost = A[i] + dp[j];
                    if (cost < min_cost) {
                        min_cost = cost;
                        next[i] = j;
                    }
                }
            }
            dp[i] = min_cost;
        }
        int i;
        for (i = 0; i < A.length && next[i] > 0; i = next[i])
            res.add(i + 1);
        if (i == A.length - 1 && A[i] >= 0)
            res.add(A.length);
        else
            return new ArrayList < Integer > ();
        return res;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(nB)$，其中 $n$ 是数组 $A$ 的长度。在每个位置处，都有 $B$ 种跳跃方式。

* 空间复杂度：$O(n)$，数组 $dp$ 和 $next$ 的大小都为 $n$。