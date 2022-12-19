### 解题思路
让指针i,j分别指向数组首尾，计算numbers[i]+numbers[j]，若两数之和大于目标，则说明此时的j和所有可用数相加都大于target，也即t于结果无用，此时应将这个数剔除，将j减1实现这一目的；反之，应将i+1。如此重复，直至找到结果。
### 代码

```python3
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        n = len(numbers)

        i = 0
        j = n - 1
        while i < j:
            if numbers[i] + numbers[j] == target:
                return [i+1, j+1]
            elif numbers[i] + numbers[j] > target:
                j -= 1
            else:
                i += 1
```
# 复杂度分析
时间复杂度：O(N)
空间复杂度：O(1)