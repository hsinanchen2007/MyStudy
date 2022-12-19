### 解题思路
此处撰写解题思路
用for循环把nums中比target小的全部遍历，最后输出其长度即可（无论里面有没有target都是在其中多加一个元素，其长度又恰好比下标多1，因此返回其长度即为target索引值。）
### 代码

```python3
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        a=[]
        for i in nums:
            if i<target:
                a.append(i)
        return len(a)

```