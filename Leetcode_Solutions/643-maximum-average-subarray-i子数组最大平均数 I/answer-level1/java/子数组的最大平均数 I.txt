#### 方法一：累计求和【通过】

**算法**

为了获得长度为 $k$ 的子数组的平均值，我们需要知道这 $k$ 个元素之和。使用 $sum$ 记录数组的累加和，$sum[i]$ 存储从第一个元素到第 $i$ 个元素之和。该数组只需要计算一次。

在数组 $sum$ 中，原数组索引从 $i$ 到 $i+k$ 的元素之和为 $sum[i] - sum[i-k]$。按照此方法遍历数组 $sum$，计算每个长度为 $k$ 的子数组平均值，即可获得长度为 $k$ 的子数组的最大平均值。

通过动画说明一个简单实例的计算过程。

<![1000](https://pic.leetcode-cn.com/Figures/643/643_Maximum_AverageSlide1.PNG),![1000](https://pic.leetcode-cn.com/Figures/643/643_Maximum_AverageSlide2.PNG),![1000](https://pic.leetcode-cn.com/Figures/643/643_Maximum_AverageSlide3.PNG),![1000](https://pic.leetcode-cn.com/Figures/643/643_Maximum_AverageSlide4.PNG),![1000](https://pic.leetcode-cn.com/Figures/643/643_Maximum_AverageSlide5.PNG),![1000](https://pic.leetcode-cn.com/Figures/643/643_Maximum_AverageSlide6.PNG),![1000](https://pic.leetcode-cn.com/Figures/643/643_Maximum_AverageSlide7.PNG),![1000](https://pic.leetcode-cn.com/Figures/643/643_Maximum_AverageSlide8.PNG)>

```java [solution1-Java]
public class Solution {
	public double findMaxAverage(int[] nums, int k) {
		int[] sum = new int[nums.length];
		sum[0] = nums[0];
		for (int i = 1; i < nums.length; i++)
		sum[i] = sum[i - 1] + nums[i];
		double res = sum[k - 1] * 1.0 / k;
		for (int i = k; i < nums.length; i++) {
			res = Math.max(res, (sum[i] - sum[i - k]) * 1.0 / k);
		}
		return res;
	}
}
```

**复杂度分析**

* 时间复杂度：$O(n)$，遍历数组 $num$，和遍历数组 $sum$ 中的 $n-k$ 个元素。

* 空间复杂度：$O(n)$，使用长度为 $n$ 的数组 $sum$ 存储累加和。 


#### 方法二：滑动窗口【通过】

**算法**

相比于创建一个累加和数组，再遍历计算最大平均值，本方法只需要遍历一次数组 $num$，从中找出长度为 $k$ 的子数组最大和。

假设我们已经索引从 $i$ 到 $i+k$ 子数组和为 $x$。要知道索引从 $i+1$ 到 $i+k+1$ 子数组和，只需要从 $x$ 减去 $sum[i]$，加上 $sum[i+k+1]$ 即可。 根据此方法可以获得长度为 $k$ 的子数组最大平均值。

```java [solution2-Java]
public class Solution {
    public double findMaxAverage(int[] nums, int k) {
        double sum=0;
        for(int i=0;i<k;i++)
            sum+=nums[i];
        double res=sum;
        for(int i=k;i<nums.length;i++){
            sum+=nums[i]-nums[i-k];
                res=Math.max(res,sum);
        }
        return res/k;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(n)$，遍历长度为 $n$ 的数组 $num$ 所需时间。 

* 空间复杂度：$O(1)$，恒定的额外空间。