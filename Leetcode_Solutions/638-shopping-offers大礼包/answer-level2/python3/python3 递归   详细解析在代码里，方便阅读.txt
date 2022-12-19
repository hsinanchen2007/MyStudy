```
class Solution:
    def shoppingOffers(self, price: List[int], special: List[List[int]], needs: List[int]) -> int:
        # 先过滤掉不划算的礼包
        special = list(filter(lambda x: x[-1] < sum(x[i]*price[i] for i in range(len(needs))), special)) 
        # 初始化钱数为原价买的钱，以后有更少的则替换
        self.costtt=sum(needs[i]*price[i] for i in range(len(needs)))
        # 若是这个钱数为零，则直接返回
        if self.costtt<=0:return 0
        # 开始递归函数（本题重点）
        def func(need,special,price,cost):
            # 如果need里不包含任何需要的物品，则将总钱数加到可能的购买钱数中。
            for i in range(len(need)):
                if need[i]>0:break
                # 如果某次递归中需求为0了，直接结账，看看此时钱数能不能更划算
                if i==len(need)-1 and need[i]==0:
                    if cost<self.costtt:self.costtt=cost
                    return
            # 关键步骤：剪枝，将不满足要求的礼包直接减去
            special=list(filter(lambda x:all(x[i]<=need[i] for i in range(len(need))),special))
            # 如果没有可选礼包，剩下的原价结账，看看此时钱数能不能更划算
            if not special:
                cost=cost+sum(need[i]*price[i] for i in range(len(need)))
                # 更划算的时候更新钱数
                if cost<self.costtt:self.costtt=cost
                return 
            # 遍历剩下的礼包，进入下一波递归
            for i in range(len(special)):
                if cost+special[i][-1]>self.costtt:continue
                # 计算买完这个礼包的钱，传入函数
                sub = [need[k]-special[i][k] for k in range(len(need))]
                func(sub,special,price,cost+special[i][-1])

        func(needs,special,price,0)
        return self.costtt
```
