## 思考
 我们有 `n + 1` 个 点 和 `n` 个区间。由于要覆盖所有区间，我们思考子问题是应该去考虑如何去 覆盖一个区间  `[i,i + 1]`，从而找到子问题。动态规划往往往难在确定状态。 所以我们往往思考最后一步到达最优解， 这里的最后一步是如何覆盖区间 `[n - 1, n]`。 假定我们已经知道了 覆盖`[0, n-1]`的最优策略。要覆盖区间 `[n - 1, n]` ，最简便的方式就是**枚举**所有覆盖该区间的水龙头，满足 ` interval.start <= n-1 &&　interval.end >= n`，那么覆盖区间`[0,n]` 的区间所需要的水龙头个数为覆盖区间  `[0, interval.start]` 需要的水龙头的数量 + 1。为了得到最右策略，我们需要选取一个最小的。


其中 interval 为 Interval 类的对象： 

```java
class Interval {
    int start;
    int end;
    Interval(int start, int end){
        this.start = start;
        this.end = end;
    }
}
```

## 状态转移方程：

根据以上的分析， 一个比较暴力的动态规划方法就出现了。
设`dp[i]` 表示区间`[0,i]`灌溉所需要的最小水龙头数量。

状态转移方程如下: 

```bash
    dp[i] = min {dp [Math.max(interval.start, 0)] + 1} , ∀ interval.start <= i-1 AND　interval.end >= i
```
note：这里的interval.start不能越界最小为0。

起始条件为： `dp[0] = 0`



## 代码 1 如下：

```java
class Solution {

    class Interval {
        int start;
        int end;
        Interval(int start, int end){
            this.start = start;
            this.end = end;
        }
    }
    
    public int minTaps(int n, int[] ranges) {

        List<Interval> intervals = new ArrayList<>();
        int pos = 0;
        // 得到所有灌溉区间。
        for (int range: ranges){
            intervals.add(new Interval(pos - range, pos + range));
            pos += 1;
        }
        
        int size = intervals.size();
        // n + 1个点一共有 n 个区间。 dp矩阵表示前i个区间所需最小的taps
        int[] dp = new int[n + 1];
        dp[0] = 0;
        for (int i = 0; i < n; i++){
            dp[i + 1] = Integer.MAX_VALUE;
            // 枚举所有覆盖它的区间。 
            for (int j =0; j < size; j++){
                if (intervals.get(j).end < i + 1 || intervals.get(j).start > i){
                    continue;
                }
                // 满足：intervals.get(j).start <= i &&  intervals.get(j).end >= i + 1                
                int start = intervals.get(j).start >= 0 ? intervals.get(j).start : 0;
                
                if (dp[start] != Integer.MAX_VALUE){
                    dp[i + 1] = Math.min(dp[i + 1], dp[start] + 1);
                }

            }
        }
        return dp[n] == Integer.MAX_VALUE ? -1 : dp[n];
    }
}
```

## 时间复杂度： 

`O(N ^ 2)` 

因为我们遍历所有位置的同时枚举所有区间。


## 小优化： 

有些区间是没有必要考虑的，所以可以通过排序 + 二分法 排除一些区间。 找到所有覆盖当前子区间的所有水龙头。

## 进一步思考， 动态规划方案 2 : 

这个动态规划的方法之所以暴力， 是因每个区间会被重复计算至区间长度次（在优化过以后）。如何减少这里的重复计算呢？我们可以从每个位置的水龙头下手，

这个水龙头要么用，要么不用。 我们可以假设使用当前的水龙头`range[i]`，那么它可以覆盖的区间为 `[i - range[i], i +  range[i]]`.

可以得到 `j ∈ [i - range[i] + 1, i +  range[i]]` 所需要的水龙头的均为 `dp[i-range[i]] + 1`。

我们可以看到这个优化的动态规划的状态和第一种方法是一致的。只是对于第一个方法的通点，枚举区间进行了改进，改进基于的观察就是每个tap要么用 要么不用。

则可以假设都用他们，去更新最优解。


## 代码 2 如下：


```java
class Solution {

    public int minTaps(int n, int[] ranges) {
        int[] dp = new int[n + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);

        // dp[i] 表示为了覆盖区间 [0,i] 所需要 的最小taps 即前i个数为止的区间。
        dp[0] = 0; 

        // 遍历所有水龙头的位置
        for (int i = 0; i <= n; i++){
            // 找到当前处的tap能覆盖的最左和最右的位置
            int left = Math.max(i- ranges[i], 0);
            int right = Math.min(i + ranges[i], n);
            for (int j = left + 1; j <= right;j++){
                //查看如果用这个tap去覆盖这些位置,所用的水龙头的位置均为前【0，left】区间所需要的水龙头的数量 + 1
                if (dp[left] != Integer.MAX_VALUE){
                     dp[j] = Math.min(dp[j], dp[left] + 1);
                }
            }
        }
        return dp[n] == Integer.MAX_VALUE ? -1: dp[n];
    }
}
```


时间复杂度：

`O(N * maxRange)`


maxrange 为所有水龙头中最大的灌溉区域长度。
 









