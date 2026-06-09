![image.png](https://pic.leetcode-cn.com/5ef7955d5f8357f96ab9fa54ea15ad4052eab7a31c9a37385d4d1cb74cb67ddf-image.png)



```
class Solution:
    def shoppingOffers(self, price: List[int], special: List[List[int]], needs: List[int]) -> int:
        item_number = len(price)
        # 预处理，将 比单买还贵的 礼包去掉
        temp_special = []
        for i in special:
            temp_cost = sum([i[j]*price[j] for j in range(item_number)])
            if temp_cost > i[-1]:
                temp_special.append(i)
        special = temp_special

        dp = {(0,)*item_number:0}
        def back(needs,special):
            min_cost = sum([needs[i]*price[i] for i in range(item_number)])
            for i in range(len(special)):
                can_buy = True
                temp_needs = [k for k in needs]
                for j in range(item_number):
                    if needs[j] < special[i][j]:
                        can_buy = False
                        break
                    temp_needs[j]-=special[i][j]
                if not can_buy:
                    continue
                if tuple(temp_needs) not in dp:      # 如果之前已经搜到了，就直接返回值
                    back(temp_needs,special[i:])
                temp_cost = special[i][-1] + dp[tuple(temp_needs)]
                if min_cost > temp_cost:
                    min_cost = temp_cost
            dp[tuple(needs)] = min_cost
        back(needs,special)
        return dp[tuple(needs)]
```
