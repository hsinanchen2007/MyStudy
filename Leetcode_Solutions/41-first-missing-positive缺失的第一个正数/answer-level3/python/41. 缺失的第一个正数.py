### 解题思路
若列表长度为n，显然缺失的正整数介于1和n+1之间，不超过n+1，这里我们通过列表来实现哈希表。

举个例子，若数组为12534，其中数据1在第一号位置，不动，2也不动，但是5却在3号位，可以看到5号位是4，那么就把5和4的位置换一下，依次对每个数进行换位，尽量使得数据i在第i号位，显然这里最多只需要交换n次，时间复杂度为O(n)。

没有额外定义数组，所以空间复杂度为O(1)。

### 代码

```python3
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        j, n = 0, len(nums)
        while j < n:
            i = nums[j]
            if i > 0 and i <= n and i != j + 1 and i != nums[i - 1]:
                nums[i - 1], nums[j] = nums[j], nums[i - 1]
                continue
            j += 1
        for i in range(n):
            if (i + 1) != nums[i]:
                return i + 1
        return n + 1
```