### 解题思路
构建一个哈希表，第一次循环将列表中所有元素放入哈希表，如果有重复元素，则将重复元素的个数增加。第二次循环，从哈希表中找出出现次数最多的元素，返回该元素。

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        dic={}
        for num in nums:
            if num in dic:
                dic[num]+=1
            else:
                dic[num]=1
        big=0
        index=0
        for d in dic:
            if dic[d]>big:
                big=dic[d]
                index=d
        return index
```