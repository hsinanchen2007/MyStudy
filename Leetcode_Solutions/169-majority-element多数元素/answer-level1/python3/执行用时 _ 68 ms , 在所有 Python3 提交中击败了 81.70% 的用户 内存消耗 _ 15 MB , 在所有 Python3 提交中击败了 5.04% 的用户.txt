### 解题思路
创建一个字典存储每个数字对应的出现次数，取出其中大于len(nums)/2的数字

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        dic = {}
        tmp = []
        if len(nums) % 2 == 0:
            times = len(nums) // 2
        else:
            times = len(nums) // 2 + 1
        for i in nums:
            if i not in tmp:
                tmp.append(i)
                dic[i] = 1
            else:
                dic[i] += 1
        for j in dic:
            if dic[j] >= times:
                return j
```