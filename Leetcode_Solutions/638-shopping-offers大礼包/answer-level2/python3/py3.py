```
# https://leetcode-cn.com/problems/shopping-offers/
class Solution:
    def shoppingOffers(self, price: List[int], special: List[List[int]], needs: List[int]) -> int:
        def available_special_list_check(special_list):
            sp_offer = special_list[:-1]
            con1 = min(i[0] - i[1] for i in zip(needs, sp_offer)) >= 0
            # con2 = sum(i[0] * i[1] for i in zip(price, special_list[:-1])) > special_list[-1]
            return con1
        available_special = [sp for sp in special if available_special_list_check(sp)]
        init_sol = sum(i[0] * i[1] for i in zip(price, needs))
        if not available_special:
            return init_sol
        sol = init_sol
        for av_sp in available_special:
            av_sp_price = av_sp[-1]
            new_need = [i[0] - i[1] for i in zip(needs, av_sp[:-1])]
            av_sp_price += self.shoppingOffers(price, special, new_need)
            sol = min(sol, av_sp_price)
        return sol

```
