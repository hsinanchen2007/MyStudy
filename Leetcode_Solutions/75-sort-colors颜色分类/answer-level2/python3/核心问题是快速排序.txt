### 解题思路
**normal method:**
1. The title says that the three colors are sorted according to specific rules. The first thing that comes to mind is to use the sorting idea to solve the problem (do not rule out that there are other Sao operations)
2. In the sort algorithm, quick sort is definitely the first choice. So obvious, solve it with quick sort

** Advanced Thoughts **
1. Through conventional methods, we can know that this is the idea of sorting, and, normally, quick sorting is the best. However, each algorithm has its place.
2. We think, what other algorithm is more suitable for this problem?
### 代码

```python3
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        Solution.QuickSort(nums, 0, (len(nums)-1))

    def QuickSort(List, start, end):
        if start > end:
            return

        left = start
        right = end
        cardinal = List[start]

        while left != right:
            if List[right] > cardinal:
                right = right - 1
            else:
                if List[left] <= cardinal:
                    left = left + 1
                else:
                    Solution.Swap(List, left, right)
                    right = right - 1            
        
        Solution.Swap(List, start, right)

        Solution.QuickSort(List, start, left-1)
        Solution.QuickSort(List, right+1, end)

    def Swap(list, left, right):
        temp = list[left]
        list[left] = list[right]
        list[right] = temp



```