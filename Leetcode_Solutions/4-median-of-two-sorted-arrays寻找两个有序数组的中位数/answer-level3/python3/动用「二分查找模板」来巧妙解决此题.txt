# 思路
+ 看到了`O(log(m+n))`和有序数列，不难想到使用「二分查找」来解决此题。
+ 可是这道题有两个数列，给找中位数带来了不小的困难，「二分查找」的细节更是举步维艰。
+ 别怕，可以使用[@liweiwei1419](/u/liweiwei1419/)大佬总结的「[二分查找模板](https://www.liwei.party/2019/06/19/leetcode-solution-new/search-insert-position/)」来快速解决细节问题。
+ 这个题解可以看作是官方题解的使用「二分查找模板」的改写。

# 代码
## 交换顺序
+ 为了减少思考，我们先假定一个序列的长度总不大于第二个。
+ 如果大于了，那么就交换一下。
+ 感谢评论区指出这样子做的原因
+ 一开始如果不交换 nums1 和 nums2 ，mid2 = half_len - mid1 可能会是负数。
```python
if len(nums1) > len(nums2):
    nums1, nums2 = nums2, nums1
```
## 记录两个序列的长度
```python
len1, len2 = len(nums1), len(nums2)
```

## 记录二分查找的信息
+ 怎么二分查找呢？
+ 假设两个序列按顺序合并了，那么中间点的位置就在`(len1 + len2 + 1) // 2`
+ 假定这个理想中位数为`x`
+ 考虑一般情况下，第一个序列存在一个数，其左边都是小于`x`，右边都大于。
+ 对第二个序列也是一样。
+ 我们对这两个数在各自序列的位置分别称作`mid1`和`mid2`。
+ 所以我们首先先对第一个序列二分查找。
+ 记录左边界，右边界为第一个序列的左右边界。
+ 而查找的中间就是左右边界的中间点。
+ 对于`mid2`，便是`(len1 + len2 + 1) // 2`减去`mid1`

```python
left, right, half_len = 0, len1, (len1 + len2 + 1) // 2
mid1 = (left + right) // 2
mid2 = half_len - mid1
```
## 更新二分查找的条件
+ 上面分析的看起来不错
+ 可是没有触及怎么更新二分查找的条件
+ 如何来更新呢？
+ 不妨这样想，最理想的情况下，两个序列的`mid1`和`mid2`应该是一样的。
+ 这时候`mid1`左侧和`mid2`左侧的数都应该比`mid1`和`mid2`对应的数小。
+ 所以可以肯定，如果`mid2`左侧的数比`mid1`对应的数都大，那么第一行的中间太靠左了。
+ 可以这么想，如果`mid2`左侧的数比`mid1`对应的都大，那不如第二行的数选小一点而第一行的数选大一点，这样两个数会更接近。
+ 要把第一行的中间往右，即二分查找的更新`left`。
+ 反之更新`right`。套用模板。
+ 记得`mid1`不要越过上限！

```python
while left < right:
    if mid1 < len1 and nums2[mid2-1] > nums1[mid1]:
        left = mid1 + 1
    else:
        right = mid1
    mid1 = (left + right) // 2
    mid2 = half_len - mid1
```
## 返回情况判断
+ 这道题还困难在它的判断条件上
+ 完成了这样的二分查找，我们找到了第一行的中间数和第二行的中间数
+ 我们要返回哪个？还是返回它们的一半？
+ 如果两个序列的长度和是奇数的话，那么就有一个唯一的中间的数
+ 而是偶数的话，就是两个中间值平均数
+ 我们假想两个序列合并并排序，那么就有这个中位数分成左右两块
+ 我们需要一个左边的最大值和一个右边的最小值
+ 如何找到左边的最大值呢？
+ 通常情况下，我们已经找到了`mid1`和`mid2`，对比这两个数。
+ 小的那个就是右边的最小值。
+ 而对比`mid1`和`mid2`左边的数，大的那个就是左边的最大值。
+ 为什么是这个逻辑呢？为什么左侧两个数的是左边的最大值，而本身就是右边的最小值呢？为什么不是它们本身两者分高低呢？（有点绕，体会一下）
+ 这样想，因为我们从`0`到`(m + n) // 2`总共共有`(m + n) // 2 + 1`个数（因为下标0也是一个数），这是大于半数的。而减去这俩中位数后，剩下的就正好是一半的数量。这即左半部分。所以我们找的`mid`其本身应该划分到右边部分。这里可以多找几个测试样例测试几次。
+ 对了，还有一些特殊情况没考虑，就是比如第一行特别小的情况下，那么左大就是二行的`mid2`偏左，而右小就是二行的`mid2`。
+ 如果总数是奇数，那么输出左大，如果是偶数，输出左大和右小的平均数。
```python
if mid1 == 0: 
    max_of_left = nums2[mid2-1]
elif mid2 == 0: 
    max_of_left = nums1[mid1-1]
else: 
    max_of_left = max(nums1[mid1-1], nums2[mid2-1])

if (len1 + len2) % 2 == 1:
    return max_of_left

if mid1 == len1: 
    min_of_right = nums2[mid2]
elif mid2 == len2: 
    min_of_right = nums1[mid1]
else: 
    min_of_right = min(nums1[mid1], nums2[mid2])

return (max_of_left + min_of_right) / 2
```
# 完整代码
```Python
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:

        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
        len1, len2 = len(nums1), len(nums2)
        
        left, right, half_len = 0, len1, (len1 + len2 + 1) // 2
        mid1 = (left + right) // 2
        mid2 = half_len - mid1
        
        while left < right:
            if mid1 < len1 and nums2[mid2-1] > nums1[mid1]:
                left = mid1 + 1
            else:
                right = mid1
            mid1 = (left + right) // 2
            mid2 = half_len - mid1
        
        if mid1 == 0: 
            max_of_left = nums2[mid2-1]
        elif mid2 == 0: 
            max_of_left = nums1[mid1-1]
        else: 
            max_of_left = max(nums1[mid1-1], nums2[mid2-1])

        if (len1 + len2) % 2 == 1:
            return max_of_left

        if mid1 == len1: 
            min_of_right = nums2[mid2]
        elif mid2 == len2: 
            min_of_right = nums1[mid1]
        else: 
            min_of_right = min(nums1[mid1], nums2[mid2])

        return (max_of_left + min_of_right) / 2
```

> 如果有问题，欢迎批评指正。