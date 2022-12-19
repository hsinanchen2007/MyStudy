这题做过一遍，结果又忘了，下定决心写一篇题解巩固一下

求连续子数组的和，很容易想到用前缀和可以O(1)的来解决：
```python
prefix = [0 for _ in range(len(nums) + 1)]
for i in range(len(nums)):
    if i == 0:
        prefix[i] = nums[i]
    else:
        prefix[i] = nums[i] + prefix[i - 1]
```
prefix[i]就代表前i位的和
因为这题长度到了10^5，O(n^2)的遍历所以可能区间来取最大值肯定不行，需要一个O(n)的方法
当时就卡在这里了，一开始想到了双指针，但是光用双指针也不可能O(n)的遍历所有区间，必然需要一个策略来更新指针的移动
这里的策略就是，尾指针遍历到哪一位，看一下头尾指针的前缀和的大小和这一个位的数的大小
如果前缀和小于这一位，说明从头指针开始的子数组必然小于从这一位开始的子数组，所以这时候把头指针移到尾指针上就行了
如果前缀和大于这一位的话，尾指针向后+1即可

```python
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        prefix = [0 for _ in range(len(nums) + 1)]
        for i in range(len(nums)):
            if i == 0:
                prefix[i] = nums[i]
            else:
                prefix[i] = nums[i] + prefix[i - 1]
        p = q = 0
        _sum = min(nums) - 1
        while q < len(nums):
            _pre =  prefix[q] if p == 0 else prefix[q] - prefix[p-1]
            if _pre < nums[q]:
                _sum = max(_sum, nums[q])
                p = q
            else:
                _sum = max(_sum, _pre)
                q += 1

        return _sum
```
