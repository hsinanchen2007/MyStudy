### 解题思路
（小白即兴，大佬勿喷）相当于提前设定两个数组A和B, 然后从nums中遍历元素, 奇数放在A，偶数放在B。然后再通过数组相加A+B即可得到结果。

### 代码

```python3
class Solution:
    def exchange(self, nums: List[int]) -> List[int]:
        self.A, self.B = [], []
        for i in range(len(nums)):
            if nums[i]%2 != 0:
                self.A.append(nums[i])
            else:
                self.B.append(nums[i])
        res = self.A + self.B
        return res







```