```
'''
LeetCode 770 基本计算器 IV
Given an expression such as expression = "e + 8 - a + 5" and an evaluation map such as {"e": 1} (given in terms of
evalvars = ["e"] and evalints = [1]), return a list of tokens representing the simplified expression, such as ["-1*a","14"]
An expression alternates chunks and symbols, with a space separating each chunk and symbol.
A chunk is either an expression in parentheses, a variable, or a non-negative integer.
A variable is a string of lowercase letters (not including digits.) Note that variables can be multiple letters,
and note that variables never have a leading coefficient or unary operator like "2x" or "-x".
Expressions are evaluated in the usual order: brackets first, then multiplication, then addition and subtraction.
 For example, expression = "1 + 2 * 3" has an answer of ["7"].
The format of the output is as follows:
For each term of free variables with non-zero coefficient, we write the free variables within a term
in sorted order lexicographically. For example, we would never write a term like "b*a*c", only "a*b*c".
Terms have degree equal to the number of free variables being multiplied, counting multiplicity.
(For example, "a*a*b*c" has degree 4.) We write the largest degree terms of our answer first,
breaking ties by lexicographic order ignoring the leading coefficient of the term.
The leading coefficient of the term is placed directly to the left with an asterisk separating it from the variables
(if they exist.)  A leading coefficient of 1 is still printed.
An example of a well formatted answer is ["-2*a*a*a", "3*a*a*b", "3*b*b", "4*a", "5*c", "-6"] 
Terms (including constant terms) with coefficient 0 are not included.  For example, an expression of "0" has an output of [].
Examples:
Input: expression = "e + 8 - a + 5", evalvars = ["e"], evalints = [1]
Output: ["-1*a","14"]
Input: expression = "e - 8 + temperature - pressure",
evalvars = ["e", "temperature"], evalints = [1, 12]
Output: ["-1*pressure","5"]
Input: expression = "(e + 8) * (e - 8)", evalvars = [], evalints = []
Output: ["1*e*e","-64"]
Input: expression = "7 - 7", evalvars = [], evalints = []
Output: []
Input: expression = "a * b * c + b * a * c * 4", evalvars = [], evalints = []
Output: ["5*a*b*c"]
Input: expression = "((a - b) * (b - c) + (c - a)) * ((a - b) + (b - c) * (c - a))",
evalvars = [], evalints = []
Output: ["-1*a*a*b*b","2*a*a*b*c","-1*a*a*c*c","1*a*b*b*b","-1*a*b*b*c","-1*a*b*c*c","1*a*c*c*c","-1*b*b*b*c",
"2*b*b*c*c","-1*b*c*c*c","2*a*a*b","-2*a*a*c","-2*a*b*b","2*a*c*c","1*b*b*b","-1*b*b*c","1*b*c*c",
"-1*c*c*c","-1*a*a","1*a*b","1*a*c","-1*b*c"]
Note:
expression will have length in range [1, 250].
evalvars, evalints will have equal lengths in range [0, 100].

题目大意：
给定一个表达式 expression 如 expression = "e + 8 - a + 5" 和一个求值映射，如 {"e": 1}
（给定的形式为 evalvars = ["e"] 和 evalints = [1]），返回表示简化表达式的标记列表，例如 ["-1*a","14"]
表达式交替使用块和符号，每个块和符号之间有一个空格。
块要么是括号中的表达式，要么是变量，要么是非负整数。
块是括号中的表达式，变量或非负整数。
变量是一个由小写字母组成的字符串（不包括数字）。请注意，变量可以是多个字母，并注意变量从不具有像 "2x" 或 "-x" 这样的前导系数或一元运算符 。
表达式按通常顺序进行求值：先是括号，然后求乘法，再计算加法和减法。例如，expression = "1 + 2 * 3" 的答案是 ["7"]。
输出格式如下：
对于系数非零的每个自变量项，我们按字典排序的顺序将自变量写在一个项中。例如，我们永远不会写像 “b*a*c” 这样的项，只写 “a*b*c”。
项的次数等于被乘的自变量的数目，并计算重复项。(例如，"a*a*b*c" 的次数为 4。)。我们先写出答案的最大次数项，用字典顺序打破关系，此时忽略词的前导系数。
项的前导系数直接放在左边，用星号将它与变量分隔开(如果存在的话)。前导系数 1 仍然要打印出来。
格式良好的一个示例答案是 ["-2*a*a*a", "3*a*a*b", "3*b*b", "4*a", "5*c", "-6"] 。
系数为 0 的项（包括常数项）不包括在内。例如，“0” 的表达式输出为 []。
示例：
输入：expression = "e + 8 - a + 5", evalvars = ["e"], evalints = [1]
输出：["-1*a","14"]
输入：expression = "e - 8 + temperature - pressure",
evalvars = ["e", "temperature"], evalints = [1, 12]
输出：["-1*pressure","5"]
输入：expression = "(e + 8) * (e - 8)", evalvars = [], evalints = []
输出：["1*e*e","-64"]
输入：expression = "7 - 7", evalvars = [], evalints = []
输出：[]
输入：expression = "a * b * c + b * a * c * 4", evalvars = [], evalints = []
输出：["5*a*b*c"]
输入：expression = "((a - b) * (b - c) + (c - a)) * ((a - b) + (b - c) * (c - a))",
evalvars = [], evalints = []
输出：["-1*a*a*b*b","2*a*a*b*c","-1*a*a*c*c","1*a*b*b*b","-1*a*b*b*c","-1*a*b*c*c","1*a*c*c*c","-1*b*b*b*c",
"2*b*b*c*c","-1*b*c*c*c","2*a*a*b","-2*a*a*c","-2*a*b*b","2*a*c*c","1*b*b*b","-1*b*b*c","1*b*c*c",
"-1*c*c*c","-1*a*a","1*a*b","1*a*c","-1*b*c"]
提示：
expression 的长度在 [1, 250] 范围内。
evalvars, evalints 在范围 [0, 100] 内，且长度相同。

解题思路：（状态转移思想）
我记得我做过其他的类似于这道题的题目，你之前做过么？这道题有前置题目，就是普通计算器，我担心你做过，你没做过的话，邮件回复我下。
这道题，其实就是多项式的四则运算，只不过就是加了一个映射表，可可以替换表达式的值。
我们可以构建一个 Poly 多项式类，实现这个多项式类的一些数学操作，单独实现每个方法都很直接，这里先列一下要实现的方法：
Poly:add(this, that) 返回 this + that 的结果。
Poly:sub(this, that) 返回 this - that 的结果。
Poly:mul(this, that) 返回 this * that 的结果。
Poly:evaluate(this, evalmap) 返回将所有的自由变量替换成 evalmap 指定常数之后的结果。
Poly:toList(this) 返回正确的多项式输出格式。
Solution::combine(left, right, symbol) 返回对 左边（left) 和 右边(left) 进行 symobl 操作之后的结果。
Solution::make(expr) 创造一个新的 Poly 实例来表示常数或 expr 指定的变量。
Solution::parse(expr) 将 expr 解析成一个 Poly 实例。
具体看代码
'''
import collections
class Poly(collections.Counter): # 继承Counter类，参考https://blog.csdn.net/qwe1257/article/details/83272340
    def __add__(self, other):
        self.update(other) # 更新other到self，参考https://www.cnblogs.com/shuopython/p/12106716.html
        return self

    def __sub__(self, other): # 看到这你应该懂，counter存的key是对应的字母等，value保存的是出现的次数，减次数就是减法
        self.update({k: -v for k, v in other.items()})
        return self

    def __mul__(self, other):
        ans = Poly() # 创建一个空的多项式
        for k1, v1 in self.items():
            for k2, v2 in other.items():
                ans.update({tuple(sorted(k1 + k2)): v1 * v2}) # 相乘后加入多项式，别忘了排序
        return ans

    def evaluate(self, evalmap): # 返回将所有的自由变量替换成 evalmap 指定常数之后的结果。
        ans = Poly()
        # print(self.items()) # dict_items([(('e',), 1), ((), 13), (('a',), -1)])
        for k, c in self.items():
            free = []
            for token in k: # 遍历键值里面的字母
                if token in evalmap: # 如果在映射表里面
                    c *= evalmap[token] # 更新对应键的值
                else:
                    free.append(token)
            ans[tuple(free)] += c # 结果是累计该值
        return ans

    def to_list(self):
        return ["*".join((str(v),) + k) for k, v in sorted(self.items(), key=lambda x: (-len(x[0]), x[0])) if v]

class Solution(object):
    def basicCalculatorIV(self, expression, evalvars, evalints):
        evalmap = dict(zip(evalvars, evalints))

        def combine(left, right, symbol): # 返回对 左边（left) 和 右边(left) 进行 symobl 操作之后的结果。
            if symbol == '+': return left + right
            if symbol == '-': return left - right
            if symbol == '*': return left * right
            else: assert False

        def make(expr): # 创造一个新的 Poly 实例来表示常数或 expr 指定的变量。
            ans = Poly()
            if expr.isdigit(): # 是数字，保存格式 -> ():数字值
                ans.update({(): int(expr)})
            else: # 不是数字，保存格式 -> (字母，):出现的次数
                ans[(expr,)] += 1
            return ans

        def parse(expr): # 将 expr 解析成一个 Poly 实例。
            bucket = [] # 数字字母表达式，保存在bucket里面，先算括号别忘了
            symbols = [] # 计算符号放到这
            i = 0
            while i < len(expr): # 遍历表达式
                if expr[i] == '(':
                    bal = 0
                    for j in range(i, len(expr)):
                        if expr[j] == '(': bal += 1
                        if expr[j] == ')': bal -= 1
                        if bal == 0: break
                    bucket.append(parse(expr[i+1:j])) # 将括号里面的递归的parse放入bucket，因为括号里面有+-以及字母数字，要递归
                    i = j # 下标更新到这
                elif expr[i].isalnum(): # Python isalnum() 方法检测字符串是否由字母和数字组成。
                    for j in range(i, len(expr)):
                        if expr[j] == ' ': # 因为题目说了，块和符号之间有空格
                            bucket.append(make(expr[i:j])) # 将遇到的字符串换算为poly格式
                            break
                    else:
                        bucket.append(make(expr[i:])) # 继续计算
                    i = j # 下标更新
                elif expr[i] in '+-*': # 遇到符号，存入symbol
                    symbols.append(expr[i])
                i += 1 # 遍历下标要一直在动哈

            for i in range(len(symbols) - 1, -1, -1): # 先算*，后算+-
                if symbols[i] == '*':
                    bucket[i] = combine(bucket[i], bucket.pop(i+1), symbols.pop(i)) # 计算*

            if not bucket: return Poly()
            ans = bucket[0] # 结果始终是bucket[0]
            for i, symbol in enumerate(symbols, 1):
                ans = combine(ans, bucket[i], symbol) # 计算+-

            return ans

        P = parse(expression).evaluate(evalmap)
        return P.to_list()

if __name__ == "__main__":
    expression = "((a - b) * (b - c) + (c - a)) * ((a - b) + (b - c) * (c - a))"
    evalvars = []
    evalints = []
    s = Solution()
    print(s.basicCalculatorIV(expression,evalvars,evalints))

```
