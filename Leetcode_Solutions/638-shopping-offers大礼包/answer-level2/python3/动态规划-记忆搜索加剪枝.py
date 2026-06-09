### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    # def shoppingOffers(self, price: List[int], special: List[List[int]], needs: List[int]) -> int:     
    def shoppingOffers(self, price, special, needs):
        dic = {}
        n = len(needs)
        special = list(filter(lambda x: x[-1] <= sum(x[i]*price[i] for i in range(n)), special))
        # getmin函数输入状态needs返回该状态的最优花费
        def getmin(needs):
            if needs in dic:
                return dic[needs]
            # 此处调用的price不变，且是类内函数因此不需要在声明getmin时传入
            # 同理needs若不变也不需要，但后面会修改needs且在嵌套函数中多次调用，因此需要传入
            res = sum([a*b for a,b in zip(price, needs)])
            # special = list(filter(lambda x: all(x[i]<=needs[i] for i in range(len(needs))), special))
            if not special:
                return res
            for sp in special:
                if all(sp[i]<=needs[i] for i in range(n)):
                    needs_next = [a-b for a,b in zip(needs, sp[:n])]
                    res = min(res, sp[-1]+getmin(tuple(needs_next)))
            dic[needs] = res
            return res
        return getmin(tuple(needs))
```