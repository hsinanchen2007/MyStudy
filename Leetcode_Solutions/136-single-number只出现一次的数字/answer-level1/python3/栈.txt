### 解题思路
先排序，定义一个空列表，逐个添加元素，如果元素已存在，则推出

### 代码

```python3
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        nums=sorted(nums)
        dic=[]
        for i in nums:
            if i in dic:
                dic.pop()
            else:
                dic.append(i)
            if len(dic)==2:
                return dic[0]
        return dic[0]
```