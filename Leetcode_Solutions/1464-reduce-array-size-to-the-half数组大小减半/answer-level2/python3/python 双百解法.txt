### 解题思路
很简单，就是挨个遍历出现次数最多的元素，只要累计的次数超过了总超度的一半就跳出然后返回。
思路分为两部分：一是统计数组各个元素出现次数，使用collections.Counter()就可以实现，其返回一个字典，key是元素，value是其出现次数
二是挨个遍历出现次数最多的元素，把字典中的key按照value进行排序，now_length是当前遍历过的元素的累计出现次数，res是遍历的元素数.

### 代码

```python3
from collections import Counter
class Solution:
    def minSetSize(self, arr):
        length=len(arr)
        arr=Counter(arr)
        res=0
        now_length=0
        for key in (sorted(arr,key=lambda x:arr[x],reverse=True)):
            now_length+=arr[key]
            res+=1
            if(now_length>=length/2):
                break
        return res
```