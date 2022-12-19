### 解题思路
见代码注释，拿示例模拟一遍即可

### 代码

```python3
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        '''
        i指向当前需要判别的元素
        j指向可以交换的元素
        '''
        len_n = len(nums)
        if len_n == 0:
            return 0
        i = 0
        j = len_n - 1

        while i < j:
            if nums[i] == val:
                # 从后往前找到第一个不是val的值(nums[j]) 从而与num[i]交换，同时要注意i<j
                while i < j and nums[j] == val:
                    j = j - 1
                    if j < 0:  # 特殊情况，单独处理
                        return 0
                if i == j:  # 特殊情况，单独处理
                    break
                # 交换，同时将j向前移动
                nums[i] = nums[i] ^ nums[j]
                nums[j] = nums[i] ^ nums[j]
                nums[i] = nums[i] ^ nums[j]
                j = j -1
            i += 1

        # 最后i==j，需要单独判断一次nums[i]的值
        return (i + 1) if nums[i] != val else i
```