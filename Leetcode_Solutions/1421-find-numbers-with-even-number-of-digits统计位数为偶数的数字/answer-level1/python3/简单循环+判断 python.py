### 解题思路
将列表里每一个元素都改成字符串类型
然后再用len计算字符串长度以算出位数
比较简单易懂的方法
### 代码

```python3
class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        count = 0
        for i in nums:
            k=len(str(i))
            if k%2 == 0:
                count += 1
        return count

```