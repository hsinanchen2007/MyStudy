#### 方法一：遍历所有满足条件的子数组【超出时间限制】

最简单的方法就是计算长度大于等于 $k$ 的所有子数组平均值，然后找出其中最大值。

从每个子数组的起始索引 $s$ 开始，遍历数组 $nums$，计算当前子数组之和。遍历到第 $i$ 个索引时，满足子数组长度大于等于 $k$ ，计算 $s$ 到 $i$ 子数组的平均值。

```java [solution1-Java]
public class Solution {
    public double findMaxAverage(int[] nums, int k) {
        double res = Integer.MIN_VALUE;
        for (int s = 0; s < nums.length - k + 1; s++) {
            long sum = 0;
            for (int i = s; i < nums.length; i++) {
                sum += nums[i];
                if (i - s + 1 >= k)
                    res = Math.max(res, sum * 1.0 / (i - s + 1));
            }
        }
        return res;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(n^2)$，对数组 $nums$ 的两层遍历。

* 空间复杂度：$O(1)$，使用恒定的额外空间。 


#### 方法二：二分查找【通过】

**算法**

$min$ 表示数组 $nums$ 的最小值，$max$ 表示数组 $nums$ 的最大值。最大平均字段和一定在最小值与最大值之间，即区间 $(min, max)$ 之间。

本方法的思想是不断猜测最大平均值，再通过验证更新猜测值，使每次猜测都更加接近正确值。如果当前猜测值太大，下一次就猜一个更小的值；如果当前猜测值太小，下一次就猜一个更大的值。

可以使用二分查找代替上面的随机猜测。以 $max$ 和 $min$ 作为初始猜测边界，每次猜测值为 $mid=(min+max)/2$。接下来需要寻找是否存在长度大于等于 $k$ 的子数组的平均值大于 $mid$。

假设在数组 $num$ 中存在一个长度为 $j$ 的子数组，它的元素为 $a_1, a_2, a_3..., a_j$，它们的平均值大于等于 $mid$。即：

$(a_1+a_2+ a_3...+a_j)/j \geq mid$ 或

$(a_1+a_2+ a_3...+a_j) \geq j*mid$ 或

$(a_1-mid) +(a_2-mid)+ (a_3-mid) ...+(a_j-mid) \geq 0$

可以看到，数组中每个元素都减去 $mid$ 后，如果存在长度大于等于 $k$ 的子数组之和大于等于 0，就表明数组 $nums$ 中存在子数组的平均和大于等于 $mid$，此时令猜测区间的下边界为 $mid$；否则令猜测区间的上边界为 $mid$，然后继续该过程。

在遍历数组 $nums$ 时，将 $nums[i]-mid$ 加到 $sum[i]$ 上。如果 $sum[k]$ 大于等于 0，则直接令猜测区间的下边界为 $mid$。否则，按照下面思路不断求 $nums$ 的前 $i$ 项之和。

数组的前 $j$ 项之和与前 $i$ 项之和分别为 $sum_j$ 与 $sum_i$。因此第 $j$ 到 $i$ 项之和为 $sum_j-sum_i$。我们希望找到一对 $i$ 和 $j$，使得 $j - i \geq k$ 时，有 $sum_j - sum_i \geq 0$。

为了实现这一点，只需要计算第 $j-k$ 到 $j$ 项之和。这是因为，如果最小的 $sum_i$ 都不能满足条件，则更大的值也无法满足条件。

这里使用变量 $prev$ 存储从第 $k$ 个位置开始的累加和。然后记录 $prev$ 中出现过的最小值，即为最小和。

每次寻找到一个新的 $mid$ 后，都将它作为猜测区间的上边界或下边界，以不断缩小猜测范围。为了保证精度，使用 $error$ 保证区间宽度小于 $10^-5$ 时，结束猜测。

```java [solution2-Java]
public class Solution {
    public double findMaxAverage(int[] nums, int k) {
        double max_val = Integer.MIN_VALUE;
        double min_val = Integer.MAX_VALUE;
        for (int n: nums) {
            max_val = Math.max(max_val, n);
            min_val = Math.min(min_val, n);
        }
        double prev_mid = max_val, error = Integer.MAX_VALUE;
        while (error > 0.00001) {
            double mid = (max_val + min_val) * 0.5;
            if (check(nums, mid, k))
                min_val = mid;
            else
                max_val = mid;
            error = Math.abs(prev_mid - mid);
            prev_mid = mid;
        }
        return min_val;
    }
    public boolean check(int[] nums, double mid, int k) {
        double sum = 0, prev = 0, min_sum = 0;
        for (int i = 0; i < k; i++)
            sum += nums[i] - mid;
        if (sum >= 0)
            return true;
        for (int i = k; i < nums.length; i++) {
            sum += nums[i] - mid;
            prev += nums[i - k] - mid;
            min_sum = Math.min(prev, min_sum);
            if (sum >= min_sum)
                return true;
        }
        return false;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(nlog(max\_val-min\_val))$。方法 $check$ 的时间复杂度为 $O(n)$，它被执行了 $O(log(max\_val-min\_val))$ 次。

* 空间复杂度：$O(1)$，使用恒定的额外空间。