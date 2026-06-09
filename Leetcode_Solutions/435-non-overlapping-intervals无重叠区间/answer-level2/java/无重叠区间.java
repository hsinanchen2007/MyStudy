#### 方法一：暴力法 【超时】

在暴力法中，我们尝试删除不同组合中的重叠间隔，然后检查哪个组合需要最少的删除次数。为此，我们首先根据起始点对区间进行排序。接着，我们使用递归函数 `eraseOverlapIntervals`，它使用上一个区间 $prev$ 的下标和当前区间 $curr$ （我们试图不移除）的下标作为参数，返回从当前下标开始需要移除的区间个数。

我们从 $prev=-1$ 和 $curr=0$ 开始。在每次递归调用中，检测当前的区间是否与上一个区间重叠。若不重叠，则不将当前区间从最终列表中移除，以 $prev=curr$ 和 $curr=curr + 1$ 调用函数 `eraseOverlapIntervals`。函数调用的结果存储在 $taken$ 变量中。

另一方面，我们也将当前区间移除调用递归，因为本区间可能和后面的区间重叠，因此移除本区间可能会导致更少的区间移除。于是，参数为 $prev=prev$ 和 $curr=curr + 1$。由于我们移除了一个区间，最后的结果应该是函数的返回值再加上 1，存储在 $notTaken$ 变量中。当返回某个特定下标对应的移除数时，返回 $taken$ 和 $notTaken$ 中的较小值。

```Java [solution 1]
public class Solution {
    class myComparator implements Comparator<Interval> {
        public int compare(Interval a, Interval b) {
            return a.start - b.start;
        }
    }
    public int eraseOverlapIntervals(Interval[] intervals) {
        Arrays.sort(intervals, new myComparator());
        return erase_Overlap_Intervals(-1, 0, intervals);
    }
    public int erase_Overlap_Intervals(int prev, int curr, Interval[] intervals) {
        if (curr == intervals.length) {
            return 0;
        }
        int taken = Integer.MAX_VALUE, nottaken;
        if (prev == -1 || intervals[prev].end <= intervals[curr].start) {
            taken = erase_Overlap_Intervals(curr, curr + 1, intervals);
        }
        nottaken = erase_Overlap_Intervals(prev, curr + 1, intervals) + 1;
        return Math.min(taken, nottaken);
    }
}
```

**复杂度分析**

* 时间复杂度：$O(2^n)$。总共可能的组合数为 $2^n$。
* 空间复杂度：$O(n)$。 递归的深度为 $n$。

---
#### 方法二：从起始点的动态规划 【通过】

**算法**

如果我们按照起始点对区间进行排序，可以很大程度上简化问题。一旦完成之后，我们就可以使用一个 $dp$ 数组，其中 $dp[i]$ 存储着只考虑到 $第i个$ 区间范围内（包括其本身），最大可能的区间数。现在，当计算 $dp[i+1]$ 时，我们不能只考虑 $dp[i]$ 的值，因为前面的 $i$ 个区间都可能与 第 $i+1$ 个区间发生重叠。因此，我们需要考虑能够使得 $j \leq i$ 且与第 $i+1$ 个区间不发生重叠的所有 $dp[j]$ 中的最大值。状态转移方程如下：
$$
dp[i+1]= \max(dp[j]) + 1,
$$

其中对于所有 $j \leq i$ ，第 i 个和第 j 个区间不发生重叠。

最后，为了计算最终列表中区间的最大区间数量，我们需要找到 $dp$ 数组中的最大值。最终的结果为区间的总数减去刚刚的结果 ($intervals.length-ans$)。

下面的动画展示了算法的流程：

<![image.png](https://pic.leetcode-cn.com/b6429db46c5953e6b1b880535b182a2de45de55f2ecdaf5766d812737bde4ee9-image.png),![image.png](https://pic.leetcode-cn.com/5d45e00542c04826c06d6712729a8b1c556c1a22e19d61ae8d60892e8268a487-image.png),![image.png](https://pic.leetcode-cn.com/33c1c1f8d7ba3f225478d29aadc8cacdcd8e7ce8b2b1cb48969c552e1d1c9f6e-image.png),![image.png](https://pic.leetcode-cn.com/9997e97d3324cde3b9733f4e8251daad11e5166084f1405371355ad71ad0a332-image.png),![image.png](https://pic.leetcode-cn.com/84dbbc310a3c15acc75aab61caa4ede9e64b90e6c3fdd2f092678a293ec2ac06-image.png),![image.png](https://pic.leetcode-cn.com/2a8889285be7b042c8b98c9c49af1284586b682c4ffd921d9e126a9479ba75cf-image.png),![image.png](https://pic.leetcode-cn.com/c28d38d085953b7d6293484a49763209c17b567f89a1fb7f1ad6b090cc7b8c31-image.png),![image.png](https://pic.leetcode-cn.com/585d763ced1ebce6575b574a831c74da1b6a4c93b75e28965da6015c465aab0f-image.png),![image.png](https://pic.leetcode-cn.com/0095bd2a360c4d429daf4420d6469b9b0f2686e2f6b238e08335a47a6cf7dc19-image.png),![image.png](https://pic.leetcode-cn.com/65917728e7e1984d27ebdfff63296dc0def75d99080a2bae81c2db2e233d880e-image.png),![image.png](https://pic.leetcode-cn.com/6c553ea4fca715bbfc3ccb6e931ec4786eda22d1aaa4065fef33f066bc9643b8-image.png),![image.png](https://pic.leetcode-cn.com/e0b31c5181ebf55919d7fc00909387f670ddb742d496ad061a408518bd1373b4-image.png),![image.png](https://pic.leetcode-cn.com/864a359646cf80c4ef07c713389b645bb9e8e5a784264a496b9aafbd4fc9d78b-image.png),![image.png](https://pic.leetcode-cn.com/48d6287f86e666105449b325004fd3b771ecea475ed5ec163236a0a08613fcab-image.png),![image.png](https://pic.leetcode-cn.com/75d2bc53df365f7c8adbccf35d93626042eaf4584ae6c755f5b99b8697d4c1dc-image.png),![image.png](https://pic.leetcode-cn.com/d926338228f1a74e494f7e16b2533c04b8e1bca5d4d415d672d4a4f99e45bac3-image.png),![image.png](https://pic.leetcode-cn.com/f0b1fdce2bbed1182ef9688a061f5f916f0a8f9960e0a199ba8cd3d30876695e-image.png),![image.png](https://pic.leetcode-cn.com/4572c11625b89598fe97045f99af261fe5ba8be915edd7381043fe4851f000f4-image.png),![image.png](https://pic.leetcode-cn.com/05fbd909c7299ee17eaa8007f7e44c1d3d9f28bee6e7f740d846451906a07997-image.png),![image.png](https://pic.leetcode-cn.com/fb1dd76009e177d4a6370cbed5431bba648c8fbec31fc22df4c7c60c35f08d10-image.png),![image.png](https://pic.leetcode-cn.com/9c72eb8da40d46f6d662ab7740b01bdd81b0fb7a575332894d5b554133e9280a-image.png),![image.png](https://pic.leetcode-cn.com/0a1312965b9b77c50375cba3077cca21b460ac4185e4b803a40df2a7bcbac660-image.png),![image.png](https://pic.leetcode-cn.com/8e6e2c9c908002363a02fad4022e0645dca948734a6ac90c3c578d44d9343ef7-image.png),![image.png](https://pic.leetcode-cn.com/4734b814060a3cdf918f1b17a43d5c8321b3669bf4b340d8e5b68333dd6e96ac-image.png),![image.png](https://pic.leetcode-cn.com/62f7eeb5110ab19dfbbec63a1e7b5341944d8cdcf4a9a2ed457d71cf9cca5c4a-image.png),![image.png](https://pic.leetcode-cn.com/e706153f43623e5b485f80962a3d6f2f48ffc9b9aa7edacdfc3296fd017e137f-image.png),![image.png](https://pic.leetcode-cn.com/9a1f974016b7a26af1b858e9e28f2458c34a496954f84e274cf0baa8060e27c1-image.png)>

```Java [solution 1]
public class Solution {
    class myComparator implements Comparator<Interval> {
        public int compare(Interval a, Interval b) {
            return a.start - b.start;
        }
    }
    public boolean isOverlapping(Interval i, Interval j) {
        return i.end > j.start;
    }
    public int eraseOverlapIntervals(Interval[] intervals) {
        if (intervals.length == 0) {
            return 0;
        }
        Arrays.sort(intervals, new myComparator());
        int dp[] = new int[intervals.length];
        dp[0] = 1;
        int ans = 1;
        for (int i = 1; i < dp.length; i++) {
            int max = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (!isOverlapping(intervals[j], intervals[i])) {
                    max = Math.max(dp[j], max);
                }
            }
            dp[i] = max + 1;
            ans = Math.max(ans, dp[i]);

        }
        return intervals.length - ans;
    }
}
```

**复杂度分析**

* 时间复杂度 : $O(n^2)$。需要两重循环。

* 空间复杂度 : $O(n)$。 $dp$ 数组占用的空间。

---
#### 方法三：从终点的动态规划 【通过】

**算法**

在上面讨论过的 DP 算法中，为了计算每个 $dp[i]$ 的值，我们需要遍历 $dp$ 数组，直到起始索引。如果我们使用根据终点排序的列表，则可以去除这一开销。我们依然使用 $dp$ 数组，其中 $dp[i]$ 用于存储存储着只考虑到 $第i个$ 区间范围内（包括其本身），最大可能的区间数。为了计算 $dp[i+1]$ ，考虑两种情况:

**情况一**

>第 $i+1$ 个区间对应的区间需要被包括在最终列表中以达到删除区间最少:

在这种情况下，我们需要从第 $i + 1$ 到开头遍历区间数组，寻找第一个不重叠的区间。这是由于，如果我们要包含当前区间，我们就需要移除所有和当前区间重叠的区间。但我们不需要每次都回到开头，相反，我们可以在找到第一个不重叠的区间后停止遍历，并用 $dp[j] + 1$ 填入 $dp[i+1]$ ，因为 $dp[j]$ 是存储 直到第 $j$ 个区间范围内最大区间数的元素。

**情况二**

> 第 $i+1$ 个区间对应的区间需要被移除以达到删除区间最少：

在这种情况下，当前元素不会被包括在最终列表中。因此，考虑到第 $i+1$ 个区间的最大数量和 只考虑到 $i$ 个的相同。因此，我们用 $dp[i]$ 的值填充 $dp[i+1]$。

最终 $dp[i+1]$ 的值为上述两值中较大的。

最终的结果为区间的总数减去 $dp$ 数组的最大值。下面的动画展示了算法过程：


<![image.png](https://pic.leetcode-cn.com/a461c499b273323942b8d3dd02734327557f095bce85bf96487068b7699814f9-image.png),![image.png](https://pic.leetcode-cn.com/1a28b2f32f64443363b3bfd3649c88054b191b300a7cdd7fbefd3af2fde99f3f-image.png),![image.png](https://pic.leetcode-cn.com/523d723679e4866beba35b2e252c6510114e99ee07ba9b597abc504d1c168d69-image.png),![image.png](https://pic.leetcode-cn.com/2c2ae424763a230b964e3e63fb13d92de0c24e61c9c85bf534c60ed117cd4954-image.png),![image.png](https://pic.leetcode-cn.com/c93fd3288ed68f58fd6d80ea120f98f05edf1e310bb0d4e8a48c0e5b60820602-image.png),![image.png](https://pic.leetcode-cn.com/a2c6e453198aee0eed3e41e952164f1a37ce49ac1c323ecf62d9c05af2bd8ee7-image.png),![image.png](https://pic.leetcode-cn.com/126e192c3db79330c398089bd7fea9b3d7790af8b3c48298bc288136dff5d196-image.png),![image.png](https://pic.leetcode-cn.com/bb58bed19fe6305e6b393355303bac53f38ed595c80b717564c0c34fb707ece8-image.png),![image.png](https://pic.leetcode-cn.com/6fc3b2b5834f92ff744371afbc38ca0152d6903adf87d5213e9c59f714449b0b-image.png),![image.png](https://pic.leetcode-cn.com/ecd9cf8ab26d33c877d6c272aa9e8ce91acf55ead1fd758c7f02a3561171ce2a-image.png),![image.png](https://pic.leetcode-cn.com/7e17e8e265db33cc2a4607093b5126937cb5a7b4711f841d3ae7d024320402b9-image.png),![image.png](https://pic.leetcode-cn.com/1b71bdec99c40f222036d7f1e0a4d291e69523da83cb679b25587fbd7fc0bac1-image.png),![image.png](https://pic.leetcode-cn.com/22224f6c024e35f56ea89202d3cd18470c2c8449f851023f2db7ad28c532bc2b-image.png),![image.png](https://pic.leetcode-cn.com/7713bf65f28830800d0ea317d3365eb897e0674ee583cb675e2bcc7b247d086b-image.png),![image.png](https://pic.leetcode-cn.com/0e5aae8aa47e35ab7da7a13f05cfd4d3a0906b54f7b83863a1018b18db7cd2fc-image.png),![image.png](https://pic.leetcode-cn.com/81465a64fa0855dcad0b6e5105d3b7a9d2809017e54d87974c3c22b117253c3b-image.png),![image.png](https://pic.leetcode-cn.com/ded3a29dafc6e92e4d3bc2651b0edcd116b9e736e8a32a82c59102e83be7f4d9-image.png),![image.png](https://pic.leetcode-cn.com/a0cabf20ec859ba19a664d6b962d483b8d8cfe61e92b2b21740483e76eca1943-image.png),![image.png](https://pic.leetcode-cn.com/e702625fb05817770dee9c3cf8696042be3af63795c98d8f08312ebc5dc89290-image.png),![image.png](https://pic.leetcode-cn.com/23f4579e64ffceb700bff7fdd2b15e0771fd0d627af1ea06ac8419bd8ddaad82-image.png),![image.png](https://pic.leetcode-cn.com/a7c9074e2e1594a4c151fe894d9caa1e0432d30a24536bfca1b8be5f39290ec3-image.png),![image.png](https://pic.leetcode-cn.com/1dc84694000237236701270eda2d19db654d8350cae4894321e37af322c3b7c2-image.png),![image.png](https://pic.leetcode-cn.com/dca58d92a27c621338909cea3900c8bf6a16d7edeaece9a83a1cc7b6c16abefa-image.png)>

```Java [solution 2]
public class Solution {
    class myComparator implements Comparator<Interval> {
        public int compare(Interval a, Interval b) {
            return a.end - b.end;
        }
    }
    public boolean isOverlapping(Interval i, Interval j) {
        return i.end > j.start;
    }
    public int eraseOverlapIntervals(Interval[] intervals) {
        if (intervals.length == 0) {
            return 0;
        }
        Arrays.sort(intervals, new myComparator());
        int dp[] = new int[intervals.length];
        dp[0] = 1;
        int ans = 1;
        for (int i = 1; i < dp.length; i++) {
            int max = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (!isOverlapping(intervals[j], intervals[i])) {
                    max = Math.max(dp[j], max);
                    break;
                }
            }
            dp[i] = Math.max(max + 1, dp[i - 1]);
            ans = Math.max(ans, dp[i]);
        }
        return intervals.length - ans;
    }
}
```


**复杂度分析**

* 时间复杂度 : $O(n^2)$。需要两重循环。

* 空间复杂度 : $O(n)$。 $dp$ 数组占用的空间。

---

####方法四：从起点的贪心算法 【通过】

**算法**

如果我们按照起点对区间进行排序，贪心算法就可以起到很好的效果。当按照起点先后顺序考虑区间的时候。我们利用一个 $prev$ 指针追踪刚刚添加到最终列表中的区间。遍历的时候，可能遇到图中的三种情况：

![image.png](https://pic.leetcode-cn.com/311ab170f5b301b3a97ebb5be89317e5c9ca47be5117b5bfbf3083ceec7346b4-image.png)

**情况一**

> 当前考虑的两个区间不重叠：

在这种情况下，不移除任何区间，将 $prev$ 赋值为后面的区间，移除区间数量不变。

**情况二**

> 两个区间重叠，后一个区间的终点在前一个区间的终点之前。

这种情况下，我们可以简单地只用后一个区间。这是显然的，因为后一个区间的长度更小，可以留下更多的空间（$A$ 和 $B$），容纳更多的区间。因此， $prev$ 更新为当前区间，移除区间的数量 + 1。

**情况三**

> 两个区间重叠，后一个区间的终点在前一个区间的终点之后。

这种情况下，我们用贪心策略处理问题，直接移除后一个区间。为了理解这种做法的正确性，请看下图，该图包含了所有可能的情况。从图可以清楚地看出，选择前移区间总会得到更好的结果。因此，$prev$ 不变，移除区间的数量 + 1。

![image.png](https://pic.leetcode-cn.com/a342372d0ddb191a3eead39b152e852e13f7b6595a4a7bf8941568efa6596df6-image.png)

```Java [solution 3]
public class Solution {
    class myComparator implements Comparator<Interval> {
        public int compare(Interval a, Interval b) {
            return a.start - b.start;
        }
    }
    public int eraseOverlapIntervals(Interval[] intervals) {
        if (intervals.length == 0) {
            return 0;
        }
        Arrays.sort(intervals, new myComparator());
        int end = intervals[0].end, prev = 0, count = 0;
        for (int i = 1; i < intervals.length; i++) {
            if (intervals[prev].end > intervals[i].start) {
                if (intervals[prev].end > intervals[i].end) {
                    prev = i;
                }
                count++;
            } else {
                prev = i;
            }
        }
        return count;
    }
}
```

**复杂度分析**

* 时间复杂度：$O\big(n \log(n)\big)$。排序需要$O\big(n \log(n)\big)$ 的时间。

* 空间复杂度：$O(1)$。不需要额外空间。

---

#### 方法五：从终点的贪心算法 【通过】

**算法**

上面讨论的贪心算法是根据起点进行贪心选择。而在本方法中，我们根据终点进行贪心选择。为此，我首先根据终点对区间进行排序。接着，对排好序的区间进行遍历。在遍历的过程中，若没有区间重叠，就不移除任何区间。如果存在重叠，就直接删除掉当前区间。

为了解释这种做法，我们继续对每种可能情况进行讨论。

![image.png](https://pic.leetcode-cn.com/373670ac0b63f74c34f7d3beac0db5d78e950d493ca9f7ac2c926313ee4445cb-image.png)


**情况一**

> 当前考虑的两个区间不重叠：

在这种情况下，不移除任何区间，将 $prev$ 赋值为后面的区间。

**Case 2:**

> 两个区间重叠，当前区间的终点在前一个区间的终点之后。

在这种情况下，如图所示，前一个区间是当前区间的真子集。因此，移除当前区间可以给别的区间更多的容纳空间。因此，保留前一个区间不变，更新当前区间。
**Case 3:**

> 两个区间重叠，当前区间的终点在前一个区间的终点之前。

在这种情况下，出现了唯一有可能移除前一个区间的机会，因为移除前一个区间可以带来 $A$ 的额外空间。然而，类似于上图的 3a 和 3b，此时也不应该移除前一个区间。然而，移除当前区间却可以带来 $B$ 的额外空间。因此，保留前一个区间不变，更新当前区间。


```Java [solution 4]
public class Solution {
    class myComparator implements Comparator<Interval> {
        public int compare(Interval a, Interval b) {
            return a.end - b.end;
        }
    }
    public int eraseOverlapIntervals(Interval[] intervals) {
        if (intervals.length == 0) {
            return 0;
        }
        Arrays.sort(intervals, new myComparator());
        int end = intervals[0].end;
        int count = 1;
        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i].start >= end) {
                end = intervals[i].end;
                count++;
            }
        }
        return intervals.length - count;
    }
}
```



**复杂度分析**

* 时间复杂度：$O\big(n \log(n)\big)$。排序需要$O\big(n \log(n)\big)$ 的时间。

* 空间复杂度：$O(1)$。不需要额外空间。
