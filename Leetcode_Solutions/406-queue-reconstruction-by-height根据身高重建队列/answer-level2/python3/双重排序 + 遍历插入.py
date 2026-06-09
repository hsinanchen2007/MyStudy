从简单示例找规律，可以先有初步结论再证明。

**思路:**
+ 根据身高进行**降序**排序，相同身高的根据前面的人数**降序**排序
+ 依次遍历排序后的list中的每一项item，根据item[1]把数据插入到指定的位置

```
from functools import cmp_to_key
class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        def cmp(x, y):
            if x[0] > y[0] or (x[0] == y[0] and x[1] < y[1]):
                return 1
            if x[0] == y[0] and x[1] == y[1]:
                return 0
            if x[0] < y[0] or (x[0] == y[0] and x[1] > y[1]):
                return -1
        people = sorted(people, key=cmp_to_key(lambda x, y: cmp(x, y)), reverse=True)
        res = []
        for item in people:
            res.insert(item[1], item)
        return res
```
