思路：
1.生成一个从0到最大值的计数列表
2.循环整个列表，进行计数
3.将每个元素的值和自己的索引进行比较

```
class Solution:
    def findLucky(self, arr: List[int]) -> int:
        data = arr
        length = len(data)
        count = [0 for i in range(max(data) + 1)]
        luck = []
        for d in range(0,length):
            count[data[d]] += 1
        for d in range(0,len(count)):
            if d == count[d]:
                luck.append(d)
        if luck:

            if count[0] == 0 and len(luck) == 1:
                return -1
            return max(luck)
        else:
            return -1
```
