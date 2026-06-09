#### 方法 1：比较排序

**想法**

按照题意实现。

**算法**

将整个数组排序后，遍历数组找到相邻元素间的最大间距。

```c++ [-C++]
int maximumGap(vector<int>& nums)
{
    if (nums.empty() || nums.size() < 2)            // check if array is empty or small sized
        return 0;

    sort(nums.begin(), nums.end());                 // sort the array

    int maxGap = 0;

    for (int i = 0; i < nums.size() - 1; i++)
        maxGap = max(nums[i + 1] - nums[i], maxGap);

    return maxGap;
}
```

**复杂度分析**

* 时间复杂度：$O(n\log n)$。排序的复杂度是 $O(n\log n)$，遍历的复杂度是 $O(n)$，总复杂度是 $O(n \log n)$。

* 空间复杂度：除去输入数组之外，不需要额外空间（因为大多数都是原地排序）。

#### 方法 2：基数排序

**算法**

这个方法与第一种方法相似，不过我们基于[基数排序](https://baike.baidu.com/item/%E5%9F%BA%E6%95%B0%E6%8E%92%E5%BA%8F/7875498?fr=aladdin)而非传统的比较排序。

```c++ []
int maximumGap(vector<int>& nums)
{
    if (nums.empty() || nums.size() < 2)
        return 0;

    int maxVal = *max_element(nums.begin(), nums.end());

    int exp = 1;                                 // 1, 10, 100, 1000 ...
    int radix = 10;                              // base 10 system

    vector<int> aux(nums.size());

    /* LSD Radix Sort */
    while (maxVal / exp > 0) {                   // Go through all digits from LSD to MSD
        vector<int> count(radix, 0);

        for (int i = 0; i < nums.size(); i++)    // Counting sort
            count[(nums[i] / exp) % 10]++;

        for (int i = 1; i < count.size(); i++)   // you could also use partial_sum()
            count[i] += count[i - 1];

        for (int i = nums.size() - 1; i >= 0; i--)
            aux[--count[(nums[i] / exp) % 10]] = nums[i];

        for (int i = 0; i < nums.size(); i++)
            nums[i] = aux[i];

        exp *= 10;
    }

    int maxGap = 0;

    for (int i = 0; i < nums.size() - 1; i++)
        maxGap = max(nums[i + 1] - nums[i], maxGap);

    return maxGap;
}
```

**复杂度分析**

* 时间复杂度：$O(d \cdot (n + k)) \approx O(n)$

  由于在数组上的线性迭代是接近线性复杂度，所以方法的时间性能瓶颈只要是基数排序。

  基数排序以[计数排序](https://baike.baidu.com/item/%E8%AE%A1%E6%95%B0%E6%8E%92%E5%BA%8F/8518144?fr=aladdin)为基础。

  * 计数排序时间复杂度是 $O(n+k)$，其中 $k$ 是数组 $n$ 个元素的基数（数字个数）。如果 $k \leq O(n)$，计数排序可以在线性时间内完成。在我们的例子中，基数是固定的（比如，$k = 10$），因此计数排序运行时间是线性的 $O(n)$。
  * 基数排序运行 $d$ 轮计数排序（其中每个元素由最多 $d$ 个数字组成）。因此有效运行时间是 $O(d \cdot (n + k))$，但在我们的例子中，最大可能的 32 位有符号是 `2147483647`，因此 $d \leq 10$ 是常数。

  因此基数排序的时间效率是 $O(n)$。

* 空间复杂度：$O(n + k) \approx O(n)$额外空间。

  计数排序需要额外 $O(k)$ 空间，基数排序需要一个和输入数组相同大小的辅助数组。然而给定的 $k$ 是一个固定小常数，所以在大输入情况下计数排序的额外空间是可以被忽略的。


#### 方法 3：桶和鸽笼原理

**想法**

对整个数组排序的代价很大，最坏情况下需要让每个元素都和其他所有元素比较。

如果我们不需要比较所有元素对呢？如果我们将元素分类，比如说用桶，这个想法将是可能的。我们只需要比较这些桶即可。

> **题外话：鸽笼原理**
>
> [鸽笼原理](https://baike.baidu.com/item/%E6%8A%BD%E5%B1%89%E5%8E%9F%E7%90%86/233776?fromtitle=%E9%B8%BD%E7%AC%BC%E5%8E%9F%E7%90%86&fromid=8942185&fr=aladdin)描述说，$n$ 个物品放入 $m$ 个容器中，如果 $n > m$ 那么一定有一个容器装有至少两个物品。

假设对于数组中的任意一个元素都有一个桶，那么每个元素恰好占据一个桶。现在减少桶的个数，必然会有一些桶包含超过一个元素。

现在讨论元素之间的间距。考虑最好情况，假设元素排好序且两两之间间距相同。这意味着任意相邻元素都有恒定的差值。所以 $n$ 个元素有 $n-1$ 个间距，假设为 $t$，显然可以得到 $t = (max - min)/(n-1)$，其中 $max$ 和 $min$ 是数组中最大和最小的元素。这个间距就是相邻元素间最大间距，也就是我们要的答案。

显然，$t$ 是具有相同数量（$n$）和相同区间（$max - min$）的数组中，都可以满足的最小值。证明：假设从一个相等间距的数组出发，改变相邻量元素的间距，假设将 $arr[i-1]$ 和 $arr[i]$ 之间的间距变成 $t - p$，那么 $arr[i]$ 和 $arr[i+1]$ 之间的间距就增长为 $t+p$。因此最大间距就从 $t$ 变成了 $t+p$，因此**最大间距** $t$ 只会增加。

**桶！**

回到我们的问题，我们已经了解了鸽笼原理的应用，那么如果我们用桶来代替单独元素作比较，比较的次数会减小，因为桶中可能有多个元素。这并不能马上解决完这个问题。如果在桶中比较元素？那问题将会得到很好解决。

所以现在的想法是：如果我们只需要在桶之间相互比较，而不用比较桶内的元素，看起来会非常理想。这也将解决排序问题：只需要将元素分配到合适的桶中，因为桶已经有序，所以我们只需要比较桶，不需要将所有元素排序并比较了。

**说明**

以下是一些说明：

* **桶的大小是相同的嘛？**

  是的，他们大小都为 $b$。

* **那么桶之间的间距也是固定的嘛？**

  是的，桶之间的间距是 1。这意味着两个大小为 3 的相邻桶分别代表的区间是 $3 - 6$ 和 $4 - 7$。不会出现重叠。

* **为什么说两个相邻桶之间可能出现最大间距？**

  桶的大小也就是桶的容积，是桶可以容纳的最大区间范围。然而桶内的区间范围取决于桶内最大元素和最小元素的差值。例如一个大小为 $5$ 的桶包含值域 $6-10$，它保存了元素 $7,8,9$ 那么实际容积就是 $(9 - 7) + 1 = 3$ 与桶的大小不相等。

+ **如何比较相邻两个桶？**

  我们比较实际范围，也就是前一个桶的最大元素和后一个桶的最小元素。比如说，两个大小为 $5$ 的桶，分别保存元素 $[1,2,3]$ 和 $[9,10]$，那么桶之间的间距就是 $9-3=6$（大于任意一个桶的大小）。

+ **是否还要再比较一次元素？！**

  是的，需要！但只需要比较两倍桶个数的元素（每个桶的最大最小元素）。如果按照上面的做法，你会发现当选择了合适的桶大小时，比较次数远远小于数组中实际元素个数。

**算法**

* 选择合适的桶大小 $b$ 满足 $1 < b \leq (max - min)/(n-1)$。设 $b = \lfloor (max - min)/(n-1) \rfloor$。
* 所有 $n$ 个元素被分为 $k = \lceil (max - min)/b \rceil$ 个桶。
* 因此第 $i$ 个桶保存的值区间为：$\bigg [min + (i-1) * b, \space min + i*b \bigg )$（下标从 `1` 开始）。
* 显然很容易计算出每个元素属于哪个桶，$\lfloor (num - min)/b \rfloor$（下标从 `0` 开始）其中 $num$ 是元素的值。
* 当所有 $n$ 个元素都遍历过后，比较 $k-1$ 个相邻桶找到最大间距。

```c++ []
class Bucket {
public:
    bool used = false;
    int minval = numeric_limits<int>::max();        // same as INT_MAX
    int maxval = numeric_limits<int>::min();        // same as INT_MIN
};

int maximumGap(vector<int>& nums)
{
    if (nums.empty() || nums.size() < 2)
        return 0;

    int mini = *min_element(nums.begin(), nums.end()),
        maxi = *max_element(nums.begin(), nums.end());

    int bucketSize = max(1, (maxi - mini) / ((int)nums.size() - 1));        // bucket size or capacity
    int bucketNum = (maxi - mini) / bucketSize + 1;                         // number of buckets
    vector<Bucket> buckets(bucketNum);

    for (auto&& num : nums) {
        int bucketIdx = (num - mini) / bucketSize;                          // locating correct bucket
        buckets[bucketIdx].used = true;
        buckets[bucketIdx].minval = min(num, buckets[bucketIdx].minval);
        buckets[bucketIdx].maxval = max(num, buckets[bucketIdx].maxval);
    }

    int prevBucketMax = mini, maxGap = 0;
    for (auto&& bucket : buckets) {
        if (!bucket.used)
            continue;

        maxGap = max(maxGap, bucket.minval - prevBucketMax);
        prevBucketMax = bucket.maxval;
    }

    return maxGap;
}
```

**复杂度分析**

* 时间复杂度：$O(n + b) \approx O(n)$。

  线性遍历一遍数组中的元素，复杂度为 $O(n)$。找到桶之间的最大间距需要线性遍历一遍所有的桶，复杂度为 $O(b)$。所以总复杂度是线性的。

* 空间复杂度：$O(2 \cdot b) \approx O(b)$ 的额外空间。

  每个桶只需要存储最大和最小元素，因此额外空间和桶个数线性相关。


