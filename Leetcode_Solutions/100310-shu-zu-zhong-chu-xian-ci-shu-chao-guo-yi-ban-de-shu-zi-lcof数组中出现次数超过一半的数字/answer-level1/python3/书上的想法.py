### 解题思路
先判断是不是候选者，再计算：
因为存在一个数，超过一半，则其余都会与它一一抵消，最后剩下的就是要找的数
### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count = 0
        candidate = None
        for num in nums:
            if count== 0:
                candidate=num
            count += (1 if num== candidate else -1)
        return candidate



```