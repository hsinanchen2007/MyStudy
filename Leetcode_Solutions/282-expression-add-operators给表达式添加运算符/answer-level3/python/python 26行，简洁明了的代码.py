核心算法是回溯
选取不同的位置插入不同的算符，得到不同的表达式，用ans存储当前表达式的值，不断回溯，如果最终表达式的值等于target，则将表达式存入results中

这个问题的难点在于乘法的优先级比加减法高，而加法减法没有本质区别，我们用另一个变量prev存储当前表达式最后一个加的数（如果是减，存相反数).接着进行回溯，在剩余字符串中选出下一个数字a，如果插入+或-，则new_ans = ans +(-) a, new_prev = (-)a，如果插入，则new_ans = ans - prev + prev  a, new_prev = a * prev
此外还要注意挑选的数字a不能是开头为0的非一位数

代码如下：
class Solution(object):
    def addOperators(self, num, target):
        """
        :type num: str
        :type target: int
        :rtype: List[str]
        """
        def calculate(num, target, expression, prev, ans, results):
            if len(num) == 0 and ans == target:
                results.append(expression)
            else:
                for i in range(1, len(num)+1):
                    if i > 1 and num[0] == '0':
                        continue
                    a = int(num[0:i])
                    if expression == '':
                        calculate(num[i:len(num)], target, num[0:i], a, a, results)
                    else:
                        calculate(num[i:len(num)], target, expression+'+'+num[0:i], a, ans+a, results)
                        calculate(num[i:len(num)], target, expression+'-'+num[0:i], -a, ans-a, results)
                        calculate(num[i:len(num)], target, expression+'*'+num[0:i], a*prev, ans+prev*(a-1), results)
        
        
        results = []
        calculate(num, target, '', 0, 0, results)
        return results