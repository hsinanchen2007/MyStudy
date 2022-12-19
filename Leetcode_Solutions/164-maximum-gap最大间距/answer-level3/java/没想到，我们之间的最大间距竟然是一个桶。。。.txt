今天分享的题目来源于 LeetCode 上第 164 号问题：最大间距。题目难度为 Hard，目前通过率为 50.4% 。

题目地址：https://leetcode-cn.com/problems/maximum-gap/

### 题目描述

给定一个无序的数组，找出数组在排序之后，相邻元素之间最大的差值。

如果数组元素个数小于 2，则返回 0。

**示例 1:**

```
输入: [3,6,9,1]
输出: 3
解释: 排序后的数组是 [1,3,6,9], 其中相邻元素 (3,6) 和 (6,9) 之间都存在最大差值 3。
```

**示例 2:**

```
输入: [10]
输出: 0
解释: 数组元素个数小于 2，因此返回 0。
```

**说明:**

- 你可以假设数组中所有元素都是非负整数，且数值在 32 位有符号整数范围内。
- 请尝试在线性时间复杂度和空间复杂度的条件下解决此问题。

### 题目解析

题意不难理解，给定一个未排序的数组，找出在排序状态下的相邻元素的最大差值。

如果不仔细看，也许你会觉得这道题简单，它最后说到要求是 **O(n)** 的时间复杂度，这也就意味着普通排序这条路是走不通的。

这里需要用到的是不经常使用的一种排序方法 —— **桶排序**！

首先简单来讲讲桶排序这个算法，这里的桶代表的是一个区间范围，每个桶的区间长度一般都是一样的，比如说给定数组 `[1,5,7,10]`，这里如果我们分 10 个桶，那么每个桶的区间长度就是 1，等同于每个桶其实就对应一个数，如果这里我们分 1 个桶，那么这个桶的区间范围就是 1 ~ 10，当然这里我给的两个例子都是极端的例子，在实际应用上我们应该结合实际情况合理分配桶。

但是基本来说**桶的范围和个数是由数组中最大值、最小值以及数组中的元素的个数来决定的**，这样可以保证使用最少的桶覆盖所有的可能性。

这个题目要求我们求数组排序好后，相邻数的最大差值，这里我们首先遍历一遍数组得到最大值、最小值，仔细想想的话，如果排序好的数组当中的元素都是等间隔的，类似 `[2,4,6,8,10]` ，在数组长度，最大最下值确定的情况下，**在这种等间隔的情况下，求得的相邻数的最大差值是最小的**，这很好理解，因为同等资源都被等量分配了，不存在分配多和少的结果。

因此，**如果我们按这个等量分配的长度来定义桶的长度的话，我们其实并不需要考虑桶内元素的差值**，我们需要做的只是记录每个桶中所有元素的最大值和最小值，然后拿这两个值去和相邻的桶的最大值和最小值做差。这样下来可以保证时间复杂度是 O(n) 的。

### 动画描述
动画加载有点慢，请稍等片刻

![](https://pic.leetcode-cn.com/b3cb1deea646b2e2c1215d41fde9085f535268cd306be8c0dffaf4063e262f9c-file_1563353660882)


### 代码实现

```java
private class Bucket {
    int min = Integer.MAX_VALUE;
    int max = Integer.MIN_VALUE;
}

public int maximumGap(int[] nums) {
    if (nums == null || nums.length < 2) {
        return 0;
    }
    
    int min = Integer.MAX_VALUE;
    int max = Integer.MIN_VALUE;
    for (int i : nums) {
        min = Math.min(min, i);
        max = Math.max(max, i);
    }
    
    // 分配桶的长度和个数是桶排序的关键
    // 在 n 个数下，形成的两两相邻区间是 n - 1 个，比如 [2,4,6,8] 这里
    // 有 4 个数，但是只有 3 个区间，[2,4], [4,6], [6,8]
    // 因此，桶长度 = 区间总长度 / 区间总个数 = (max - min) / (nums.length - 1)
    int bucketSize = Math.max(1, (max - min) / (nums.length - 1));
    
    // 上面得到了桶的长度，我们就可以以此来确定桶的个数
    // 桶个数 = 区间长度 / 桶长度
    // 这里考虑到实现的方便，多加了一个桶，为什么？
    // 还是举上面的例子，[2,4,6,8], 桶的长度 = (8 - 2) / (4 - 1) = 2
    //                           桶的个数 = (8 - 2) / 2 = 3
    // 已知一个元素，需要定位到桶的时候，一般是 (当前元素 - 最小值) / 桶长度
    // 这里其实利用了整数除不尽向下取整的性质
    // 但是上面的例子，如果当前元素是 8 的话 (8 - 2) / 2 = 3，对应到 3 号桶
    //              如果当前元素是 2 的话 (2 - 2) / 2 = 0，对应到 0 号桶
    // 你会发现我们有 0,1,2,3 号桶，实际用到的桶是 4 个，而不是 3 个
    // 透过例子应该很好理解，但是如果要说根本原因，其实是开闭区间的问题
    // 这里其实 0,1,2 号桶对应的区间是 [2,4),[4,6),[6,8)
    // 那 8 怎么办？多加一个桶呗，3 号桶对应区间 [8,10)
    Bucket[] buckets = new Bucket[(max - min) / bucketSize + 1];
    
    for (int i = 0; i < nums.length; ++i) {
        int loc = (nums[i] - min) / bucketSize;
        
        if (buckets[loc] == null) {
            buckets[loc] = new Bucket();
        }
        
        buckets[loc].min = Math.min(buckets[loc].min, nums[i]);
        buckets[loc].max = Math.max(buckets[loc].max, nums[i]);
    }
    
    int previousMax = Integer.MAX_VALUE; int maxGap = Integer.MIN_VALUE;
    for (int i = 0; i < buckets.length; ++i) {
        if (buckets[i] != null && previousMax != Integer.MAX_VALUE) {
            maxGap = Math.max(maxGap, buckets[i].min - previousMax);
        }
        
        if (buckets[i] != null) {
            previousMax = buckets[i].max;
            maxGap = Math.max(maxGap, buckets[i].max - buckets[i].min);
        }
    }
    
    return maxGap;
}

```

