### 53 最大子序和 解法分析

初看这道题，思路基本就是用遍历的方法，就这个例子来说，一共有9个数字，我们把所有的排列组合列出来，然后求出最大值。按照排列组合的数学算法，一共有45个组合，如果有n个数字，时间复杂度是$O(n^2)$，这样的时间复杂度是明显不能接受的。

#### 解法1 动态规划

于是我们把目光落到动态规划上面来，首先需要把这个问题分解成**最优子问题**来解。最主要的思路就是将上面的45个组合进行分类，分解成数量较少的几个子问题。在这里我们一共有9个数字，顺理成章的我们把组合分解成9个小组的组合。

1. 第一个子组合是以第一个数字结尾的连续序列，也就是``[-2]``，最大值-2

2. 第二个子组合是以第二个数字结尾的连续序列，也就是``[-2,1], [1]``，最大值1

3. 第三个子组合是以第三个数字结尾的连续序列，也就是``[-2,1,3], [1,3], [3]``，最大值4

4. 以此类推。。。

如果我们能够得到每一个子组合的最优解，也就是子序列的最大值，整体的最大值就可以通过比较这9个子组合的最大值来得到了。现在我们找到了最优子问题，**重叠子问题**在哪呢？那就得细心比较一下每个子问题。

从第二个子组合和第三个子组合可以看到，组合3只是在组合2的基础上每一个数组后面添加第3个数字，也就是3，然后增加一个只有第三个数字的数组``[3]``。这样两个组合之间的关系就出现了，可是我们不关心这个序列是怎么生成的，只是关心最大值之间的关系。我们将子组合三分成两种情况：

1. 继承子组合二得到的序列，也就是``[-2,1,3], [1,3]`` （最大值 = 第二个组合的最大值 + 第三个数字）
2. 单独第三个数字的序列，也就是``[3]`` （最大值 = 第三个数字）

如果第二个序列的最大值大于0，那么最大值1就比最大值2要大，反之最大值2较大。这样，我们就通过第二个组合的最大值和第三个数字，就得到了第三个组合的最大值。因为第二个组合的结果被重复用到了，所以符合这个重叠子问题的定义。通俗来讲这个问题就变成了，第i个子组合可以通过第i-1个子组合的最大值和第i个数字获得，如果第i-1个子组合的最大值没法给第i个数字带来正增益，我们就抛弃掉前面的子组合，自己就是最大的了。
$$
\begin{aligned}
&如果Max(i-1) > 0, Max(i) = Max(i-1) + Nums(i) \\
&如果Max(i-1) <= 0, Max(i) = Nums(i)
\end{aligned}
$$

来看看代码，我们只需要一个变量``subMax``保存前面子组合的最大值，另外一个``max``保存全局最大值。

```java
    public int maxSubArray(int[] nums) {
        if (nums == null) {
            return 0;
        }

        int max = nums[0];    // 全局最大值
        int subMax = nums[0];  // 前一个子组合的最大值
        for (int i = 1; i < nums.length; i++) {
            if (subMax > 0) {
                // 前一个子组合最大值大于0，正增益
                subMax = subMax + nums[i];
            } else {
                // 前一个子组合最大值小于0，抛弃前面的结果
                subMax = nums[i];
            }
            // 计算全局最大值
            max = Math.max(max, subMax);
        }

        return max;
    }
```

#### 解法2 分治法

分治法是将整个数组切分成几个小组，每个小组然后再切分成几个更小的小组，一直到不能继续切分也就是只剩一个数字为止。然后每个小组会计算出最优值，汇报给上一级的小组，一级一级汇报，上级拿到下级的汇报找到最大值，得到最终的结果。和合并排序的算法类似，先切分，再合并结果。

这个问题中的关键就是如何切分这些组合才能使每个小组之间不会有重复的组合（有重复的组合意味着有重复的计算量），这个问题应该困扰了不少的同学，我在学习理解的时候也花了不少时间。

首先是切分分组方法，就这个案例中的例子来，我们有一个数组``[-2,1,-3,4,-1,2,1,-5,4]``，一共有9个元素，我们``center=(start + end) / 2``这个原则，得到中间元素的索引为4，也就是``-1``，拆分成三个组合：

- ``[-2,1,-3,4,-1]``以及它的子序列（在``-1``左边的并且包含它的为一组）
- ``[2,1,-5,4]`` 以及它的子序列（在``-1``右边不包含它的为一组）
- 任何包含``-1``以及它右边元素``2``的序列为一组（换言之就是包含**左边序列的最右边元素**以及**右边序列最左边元素**的序列，比如``[4,-1,2,1]``，这样就保证这个组合里面的任何序列都不会和上面两个重复）

以上的三个组合内的序列没有任何的重复的部分，而且一起构成所有子序列的全集，计算出这个三个子集合的最大值，然后取其中的最大值，就是这个问题的答案了。

然而前两个子组合可以用递归来解决，一个函数就搞定，第三个跨中心的组合应该怎么计算最大值呢？

答案就是先计算左边序列里面的包含最右边元素的的子序列的最大值，也就是从左边序列的最右边元素向左一个一个累加起来，找出累加过程中每次累加的最大值，就是左边序列的最大值。同理找出右边序列的最大值，就得到了右边子序列的最大值。左右两边的最大值相加，就是包含这两个元素的子序列的最大值。

在计算过程中，累加和比较的过程是关键操作，一个长度为$n$的数组在递归的每一层都会进行$n$次操作，分治法的递归层级在$logN$级别，所以整体的时间复杂度是$O(nlogn)$，在时间效率上不如动态规划的$O(n)$复杂度。

代码如下

```java
    public int maxSubArray(int[] nums) {
        return maxSubArrayDivideWithBorder(nums, 0, nums.length-1);
    }

    private int maxSubArrayDivideWithBorder(int[] nums, int start, int end) {
        if (start == end) {
            // 只有一个元素，也就是递归的结束情况
            return nums[start];
        }

        // 计算中间值
        int center = (start + end) / 2;
        int leftMax = maxSubArrayDivideWithBorder(nums, start, center); // 计算左侧子序列最大值
        int rightMax = maxSubArrayDivideWithBorder(nums, center + 1, end); // 计算右侧子序列最大值

        // 下面计算横跨两个子序列的最大值

        // 计算包含左侧子序列最后一个元素的子序列最大值
        int leftCrossMax = Integer.MIN_VALUE; // 初始化一个值
        int leftCrossSum = 0;
        for (int i = center ; i >= start ; i --) {
            leftCrossSum += nums[i];
            leftCrossMax = Math.max(leftCrossSum, leftCrossMax);
        }

        // 计算包含右侧子序列最后一个元素的子序列最大值
        int rightCrossMax = nums[center+1];
        int rightCrossSum = 0;
        for (int i = center + 1; i <= end ; i ++) {
            rightCrossSum += nums[i];
            rightCrossMax = Math.max(rightCrossSum, rightCrossMax);
        }

        // 计算跨中心的子序列的最大值
        int crossMax = leftCrossMax + rightCrossMax;

        // 比较三者，返回最大值
        return Math.max(crossMax, Math.max(leftMax, rightMax));
    }
```

#### 解法3 Kadane算法

Kadane全名叫Joseph "Jay" Born Kadane，是卡耐基梅隆大学的统计学方面的教授，于1984年提出提出了线性解决这个问题的办法。

国内网上有很多材料提到了Kadane算法，并且将Kadane算法和动态规划并列到了一起，表明是两个不同的算法，但是当搜索外文网站的时候，大家用的Kadane算法和动态规划的思路是一模一样的，参考我的第一个参考文章，这里贴一下[Wikipedia](https://en.wikipedia.org/wiki/Maximum_subarray_problem)的代码，感觉和我们的动态规划的算法似乎不太一样

```python
def max_subarray(numbers):
    """Find a contiguous subarray with the largest sum."""
    best_sum = 0  # or: float('-inf')
    current_sum = 0
    for x in numbers:
        current_sum = max(0, current_sum + x)
        best_sum = max(best_sum, current_sum)
    return best_sum
```

我们把这个代码放到网站跑一边，发现没有通过，因为当这个数组全是负数的时候，它的结果是0，改进方法是把``max(0, current_sum + x)``换成``max(x, current_sum + x)``，这样就没有问题了：

```python
def max_subarray(numbers):
    """Find a contiguous subarray with the largest sum."""
    best_sum = 0  # or: float('-inf')
    current_sum = 0
    for x in numbers:
        current_sum = max(x, current_sum + x)
        best_sum = max(best_sum, current_sum)
    return best_sum
```

现在大家有没有感觉这段代码很眼熟，没错！这就是我们的动态规划的解法。和原来的一样，核心思路都是判断以前一个元素结尾的子序列的最大值能不能给当前元素结尾的序列提供增益。当初布朗大学的Ulf Grenander教授在1977年提出这个问题的时候是为了展示数字图像中一个简单的最大似然估计模型，可能没有过多考虑道负数的问题，所以后来在解决的时候就没有考虑到全是负数的情况。

### 延伸——获取最大序列的起始和结束位置

可以使用我们的第一种方法也就是动态规划的方法来找到这个位置，将以这个元素结尾的的最大子序列的位置找出来，然后每次比较最大值的时候更新一下最大值的位置就行了

```java
    public int maxSubArrayPosition(int[] nums) {
        if (nums == null) {
            return 0;
        }

        int start = 0;
        int end = 0;
        int subStart = 0;
        int subEnd = 0;
        int max = nums[0];    // 全局最大值
        int subMax = nums[0];  // 前一个子组合的最大值
        for (int i = 1; i < nums.length; i++) {
            if (subMax > 0) {
                // 前一个子组合最大值大于0，正增益，更新最后元素位置
                subMax = subMax + nums[i];
                subEnd++;
            } else {
                // 前一个子组合最大值小于0，抛弃前面的结果，更新当前最大值位置
                subMax = nums[i];
                subStart = i;
                subEnd = i;
            }
            // 计算全局最大值，更新位置，将全局最优解的位置更新
            if (subMax > max) {
                max = subMax;
                start = subStart;
                end = subEnd;
            }
        }

        System.out.println("[" + start + ","+ end +"]");
        return max;
    }
```

### 参考

> [Kadane’s Algorithm Explained](https://hackernoon.com/kadanes-algorithm-explained-50316f4fd8a6)
> [Maximum subarray problem](https://en.wikipedia.org/wiki/Maximum_subarray_problem)
> [求最大连续子序列的和，两种解法：动态规划 & Kadane算法](https://blog.csdn.net/wangbaochu/article/details/53045555)
> [分治策略结合递归思想求最大子序列和](https://blog.csdn.net/abnerwang2014/article/details/36027747)
> [Kadane’s Algorithm — (Dynamic Programming) — How and Why does it Work?](https://medium.com/@rsinghal757/kadanes-algorithm-dynamic-programming-how-and-why-does-it-work-3fd8849ed73d)

想看更多可以来我的博客——[悟Space](http://sunshuyi.vip)