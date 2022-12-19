### 解题思路
此题同题 [面试题40. 最小的k个数](https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/)
[215. 数组中的第K个最大元素](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/)

可以进一步看题解 [gelthin-快排-partition-这题需要反复做](https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/solution/gelthin-kuai-pai-partition-by-gelthin/)

这里分析了最坏情况的时间复杂度 O(k*n), 当所有元素的值都相同时，每次 partition 只能排除一个元素。

### 代码

```python3
class Solution:

    def partition(self, arr, left, right):
        pivot = arr[right]
        i = left
        for j in range(left, right): # 不取right
            if arr[j] < pivot:
                arr[i], arr[j] = arr[j], arr[i]
                i += 1
        arr[i], arr[right] = arr[right], arr[i]

        return i

    def smallestK(self, arr: List[int], k: int) -> List[int]:
        l = len(arr)  # 已知 k <= l
        if k==0:
            return []
        if l == k:
            return arr
        # select the kth smallest number
        left, right = 0, l-1
        while left <= right:
            ind = self.partition(arr,left,right)#当所有元素相同时,ind= left,每次只前进一个元素,效率最低 O(n*k)
            if ind == k:
                break
            elif ind > k:
                right = ind - 1  
            else:
                left = ind + 1
        return arr[:k]
```