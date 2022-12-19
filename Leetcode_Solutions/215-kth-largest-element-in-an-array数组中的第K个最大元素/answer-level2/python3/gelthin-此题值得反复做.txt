### 解题思路
同习题： [面试题40. 最小的k个数](https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/)
[面试题 17.14. 最小K个数](https://leetcode-cn.com/problems/smallest-k-lcci/)


[medians' median  BFPRT 算法](https://blog.csdn.net/laojiu_/article/details/54986553)
似乎与 huangyu 老师的讲法有些出入


此题解法(第 k 大):

+ 冒泡排序（选择排序）k 次: O(k*n)
+ 快速排序： O(nlogn)
+ 堆排序（大顶堆）： O(n) + O(k*logn)
+ 堆排序（小顶堆）：O(k) + O((n-k)*logk) = O(n*logk)
+ 次序排序 partition： 期望下 O(n)
+ medians' median  BFPRT 算法： O(n)

关于 partition 的实现，有一些细节，例如 while left < right 还是 while left <= right


### 代码

```python3
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        def partition(nums, left, right):
            pivot = nums[right]
            i = left
            for j in range(left, right+1):
                if nums[j]<pivot:
                    nums[i], nums[j] = nums[j], nums[i]
                    i += 1
            nums[i], nums[right] = nums[right], nums[i]
            return i

        n = len(nums)
        t = n-k 
#        if not (0<= t <= n-1):
#            return
        left, right = 0, n-1
        while left < right:   # 若设置成 left < right 如果下面没有语句的话，可能会漏解， 例如 [3]
            ind = partition(nums, left, right)
            if ind == t:
                return nums[ind]
            elif ind < t:
                left = ind + 1
            else:
                right = ind-1
        return nums[left]  # 对应前面 left<right, 若前面设置为 left <= right, 则不用此语句
```