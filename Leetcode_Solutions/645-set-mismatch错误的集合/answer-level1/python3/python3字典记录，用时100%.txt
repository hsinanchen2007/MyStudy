### 解题思路
![image.png](https://pic.leetcode-cn.com/f1403a2ca41d8cbdda78692c2abd6f10dfa97ad4ed71330386973e5ebb66bab3-image.png)
用字典存元素出现的次数，出现两次的记为a，1-n中没出现的记为b。
### 代码

```python3
class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        n = len(nums)
        dct = {}
        a = 0  # 被复制的数
        b = 0  # 丢失的数
        for each in nums:
            dct[each] = dct.get(each , 0) + 1
        for i in range(1 , n + 1):
            if i not in dct:
                b = i
                dct[i] = 0
            if dct[i] == 2:
                a = i
        return [a , b]
```