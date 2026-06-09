class Solution:
    def numberOfSteps (self, num: int) -> int:
        steps = 0

        while num > 0: 
            if num % 2 == 0:
                num = num / 2
                steps += 1
            else:
                num -= 1
                steps += 1
        
        return steps

还有一个思路是把else语句删除，return steps + 1
但是执行提示错误：超出时间限制。
