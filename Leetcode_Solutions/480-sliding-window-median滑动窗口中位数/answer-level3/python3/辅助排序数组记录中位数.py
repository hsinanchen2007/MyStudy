- 本题用堆也可以，但是python中的heapq没有删除操作，所以考虑用排序数组。
- **时间复杂度**：一开始的预先排序花费O(klog(k))，遍历数组中的n-k个元素，每次增加操作和删除操作都采用二分搜索O(log(k))，增加和删除操作用python的库函数bisect，所以总的时间复杂度是O(nlog(k))。
- 再对比一下堆，堆的增加和删除（sift up/down）也是需要log(k)的复杂度，遍历数组之后两者复杂度持平。
- **空间复杂度**：辅助数组需要O(k)，其实中位数可以通过in-place来替换，实现总体O(k)的空间复杂度（下面的代码没有用in-place替换）。

```
import bisect
class Solution:
    def medianSlidingWindow(self, nums: List[int], k: int) -> List[float]:
        """
        My solution, using sorted list

        Time: O(nlog(k))
        Space: O(n+k)
        """
        res = []
        if not nums or not k:
            return res

        def append_median():
            median = sorted_list[k//2] if k%2==1 else (sorted_list[k//2] + sorted_list[k//2-1])/2
            res.append(median)

        n = len(nums)
        p1, p2 = 0, k
        sorted_list = sorted(nums[p1:p2])
        append_median()

        while p2 != n:
            bisect.insort(sorted_list, nums[p2])
            del_index = bisect.bisect(sorted_list, nums[p1])
            # remember that the index of bisect and list are not same!
            del sorted_list[del_index - 1]
            append_median()
            
            p1 += 1
            p2 += 1

        return res
```
