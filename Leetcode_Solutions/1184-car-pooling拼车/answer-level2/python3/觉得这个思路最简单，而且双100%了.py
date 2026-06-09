![图片1.png](https://pic.leetcode-cn.com/ee19257866f6a0b8c128ef5f32b8de1f05a9f4f2a7c285553aebb7e0423b6918-%E5%9B%BE%E7%89%871.png)

拆分原来的数组为上车点乘客人数为正，下车点乘客数设为负数，然后排序（需要注意先下后上），最后遍历看看每个站点的时候人数是否超载即可。

这个思路和坛子里很多童鞋不谋而合，我实现的结果双100%了，因此发表下。

```
class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        travel = []
        for i in trips:
            travel.append([i[1], i[0]])
            travel.append([i[2], -i[0]])
        travel.sort(key = lambda x:(x[0], x[1])) #注意先下后上
        people_in_car = 0
        for i in travel:
            people_in_car += i[1]
            if people_in_car > capacity: return False
        return True
```

