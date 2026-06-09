```
class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        ### answers中，回答数字相同的兔子的颜色可能是相同的
        ### 如果回答的数字是不相同的，就肯定是不同的
        ### 把回答的数字相同的兔子尽量放在一个颜色
        Hash = {}
        for answer in answers:
            if answer not in Hash:
                Hash[answer] = 0
            Hash[answer] += 1
        res = 0
        while Hash:
            answer, amount = Hash.popitem()
            ### 如果能整除，就把全部的兔子平分到不同的组好了
            if amount % (answer + 1) == 0:
                res += amount
            ### 如果不能整除，就把多余的兔子另开一组
            else:
                res +=  (answer + 1) * (amount // (answer + 1) + 1)
        return res


```
