思路：如果顾客bill为5，将当前5元零钱数加一。
    若顾客bill为10或20， 则调用searchChange函数判断当前5元和10元的零钱数能否正确找零。
    注意，当bill为20时，优先考虑使用10元零钱进行找零，即先判断“if cur_10 >= 1 and cur_5 >=1”是否满足，
    若不满足再考虑使用3个5元找零。
```
class Solution(object):
    def __init__(self):
        # 初始化当前零钱数量
        self.cur_5 = 1
        self.cur_10 = 0
    def lemonadeChange(self, bills):
        """
        :type bills: List[int]
        :rtype: bool
        """     
        if bills[0] != 5:
            return False
    
        for i in range(1, len(bills)):
            # 顾客bill一共存在三种情况
            if bills[i] == 5:
                self.cur_5 += 1
                isChange = True
            elif bills[i] == 10:
                isChange = self.searchChange(10, self.cur_5, self.cur_10)
            else:
                isChange = self.searchChange(20, self.cur_5, self.cur_10)
            # 通过返回的isChange判断当前bill能否正确找零，若能，则继续遍历，若不能则直接返回False
            if isChange:
                continue
            else:
                return False
        return True
    
    def searchChange(self, bill, cur_5, cur_10):
        # isChange用于记录能否正确找零，初始化为False
        isChange = False
        # bill为10的情况，判断5元零钱是否大于1，若大于1，则可以正确找零，更新isChange为True
        if bill == 10 and cur_5 >= 1:
            self.cur_5 -= 1
            self.cur_10 += 1
            isChange = True
        # bill为20的情况，优先考虑使用10元零钱找零 
        if bill == 20:
            if cur_10 >= 1 and cur_5 >=1:
                self.cur_5 -= 1
                self.cur_10 -= 1
                isChange = True
            elif cur_5 >= 3:
                self.cur_5 = cur_5 - 3
                isChange = True
            else:
                isChange = False
            
        return isChange

```

