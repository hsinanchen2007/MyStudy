```
'''
LeetCode 224. 基本计算器
Implement a basic calculator to evaluate a simple expression string.
The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .
Example 1:
Input: "1 + 1"
Output: 2
Example 2:
Input: " 2-1 + 2 "
Output: 3
Example 3:
Input: "(1+(4+5+2)-3)+(6+8)"
Output: 23
Note:
You may assume that the given expression is always valid.
Do not use the eval built-in library function.

题目大意：
实现一个基本的计算器来计算一个简单的字符串表达式的值。
字符串表达式可以包含左括号 ( ，右括号 )，加号 + ，减号 -，非负整数和空格  。
示例 1:
输入: "1 + 1"
输出: 2
示例 2:
输入: " 2-1 + 2 "
输出: 3
示例 3:
输入: "(1+(4+5+2)-3)+(6+8)"
输出: 23
说明：
你可以假设所给定的表达式都是有效的。
请不要使用内置的库函数 eval。

解题思路：
这道题是一道hard题目，难点就在于如何处理括号
解决这个问题需要理解以下内容：
输入始终包含有效的字符串。
加减法规则。
括号中的优先含义。
空格不影响输入表达式的计算。

方法一：栈和反转字符串
栈是一种先进后出的数据结构，在计算机中，栈常被理解一种保护现场与恢复现场的功能。
我们需要理解 + 和 - 的区别。+ 遵循结合律。例如 A+B+C，等价为 (A+B)+C = A+(B+C)。- 不遵循这个一规则，这是该方法的难点。
如果我们使用栈并从左到右读取表达式的元素，则最终我们会从右到左计算表达式。
就会出现 (A-B)-C 等于 (C-B)-A 的情况，这是不正确的。减法即不遵循结合律也不遵循交换律。
这个问题很容易解决，我们通过反转字符串，然后再按需添加到栈中，我们将字符串从右到左放入栈中，实现从左到右正确的计算表达式。
具体的：
1，按逆序迭代字符串。
2，操作数转为十进制，读取的字符是一个数字，要将读取的数字乘以 10 的幂并将当前数字相加，形成操作数。因为我们是按逆序处理字符串。
3，操作数由多个字符组成，一旦我们遇到的字符不是数字，则我们将操作数添加到栈上，这代表读取好了一个完整的数。
4，当我们遇到最括号 (，这意味这遇到了一个子表达式结束。由于我们是逆序，所以开括号成了表达式的结尾。
则需要从栈中弹出操作数和运算发来计算表达式，直到弹出相应的右括号。子表达式的最终结果最终添加到栈上。
这里面的思想是，遇到括号先用栈保存现场，然后再恢复现场。
5，将非数字字符添加到栈上。
6，这个做直到我们得到最终的结果。可能我们没有更多的字符要处理，但是栈仍然是非空的。
当主表达式没有用括号括起来时，就会发生这种情况。因此，在完成对整个表达式求值之后，我们将检查栈是否非空。
如果是的话，我们将栈中的元素作为最终表达式处理，并像遇到左括号时那样对其求值。
class Solution:
    def evaluate_expr(self, stack): # 这是不考虑括号的计算当前表达式的值，也可以理解为计算括号内的全部值
        res = stack.pop() if stack else 0
        while stack and stack[-1] != ')': # # 计算栈内表达式保存到res，直到遇到右括号
            sign = stack.pop()
            if sign == '+':
                res += stack.pop()
            else:
                res -= stack.pop()
        return res

    def calculate(self, s: str) -> int:
        stack = []
        n, operand = 0, 0 # n是读取字符时候，记录个十百千万的， operand是当前数
        for i in range(len(s) - 1, -1, -1): # 逆序遍历，因为栈是反着的，且括号的存在，我们不可以逆序计算，-不满足结合结合律
            ch = s[i]
            if ch.isdigit():
                operand = (10**n * int(ch)) + operand # 因为是逆序读取的，所以这样计算
                n += 1
            elif ch != " ":
                if n:  # 遇到括号时候，先判断当前n，n是读取数字的个十百千万，所以n不为0代表前面读取了数字，入栈
                    stack.append(operand)
                    n, operand = 0, 0 # 刷新，方便下次迭代读取数字
                if ch == '(':
                    res = self.evaluate_expr(stack) # 因为是从右边往左遍历，遇到左括号才是结尾，并计算当前括号内的值
                    stack.pop()
                    stack.append(res) # 更新栈顶为计算后的结果
                # For other non-digits just push onto the stack.
                else: # 其他的入栈，因为只有遇到（，才会计算括号内的值
                    stack.append(ch)
        if n:   # 如果还有最后一个数，入栈
            stack.append(operand)
        return self.evaluate_expr(stack) # 对于有最后一个数的，把它也计算了，如1+（2+3）与（1+2）+3，后面是有最后一个数的

方法2：栈和不反转字符串
解决 - 结合律的问题的一个简单的方法就是使将 - 运算符看作右侧操作数的大小。一旦我们将 - 看作操作数的大小，则表达式将只剩下一个操作符。
就是 + 运算符，而 + 是遵循结合律的。如A-B-C等于A+(−B)+(−C)。
重写以后的表达式将遵循结合律，所以我们从左或从右计算表达式都是正确的。
需要注意的是给定的表达式会很复杂，即会有嵌套在其他表达式的表达式。即 (A - (B - C))，
需要 B-C 外面的 - 号与 B-C 关联起来，而不是仅仅与 B 关联起来。
算法：
1，正序迭代字符串。
2，操作数可以由多个字符组成，读取的字符是一个数字，则我们要将先前形成的操作数乘以 10 并于读取的数字相加，形成操作数。
3，每当我们遇到 + 或 - 运算符时，我们首先将表达式求值到左边，然后将正负符号保存到下一次求值。
4，如果字符是左括号 (，我们将迄今为止计算的结果和符号添加到栈上，然后重新开始进行计算，就像计算一个新的表达式一样，这也就是保护现场
5，如果字符是右括号 )，则首先计算左侧的表达式。则产生的结果就是刚刚结束的子表达式的结果。如果栈顶部有符号，则将此结果与符号相乘。
直接看代码
'''
class Solution:
    def calculate(self, s: str) -> int:

        stack = []
        operand = 0 # 当前数
        res = 0 # 当前结果
        sign = 1 # 1代表正数，-1代表负数

        for ch in s:
            if ch.isdigit():
                operand = (operand * 10) + int(ch) # 字符转十进制数
            elif ch == '+': # 遇到加法，先计算当前结果
                res += sign * operand # 当前结果=上一次结果+当前数字（此时遍历到+，当前数字是上面的operand）*上次符号
                sign = 1 # 更新当前操作符号为+
                operand = 0 # 清空当前数
            elif ch == '-':
                res += sign * operand
                sign = -1
                operand = 0
            elif ch == '(': # 遇到左括号，先计算左括号，保护现场，把当前res先push到栈，把当前符号push到栈
                stack.append(res)
                stack.append(sign)
                sign = 1 # 重置为一开始的，括号里我们就当作重新开始计算了
                res = 0
            elif ch == ')': # 遇到右括号，你知道的，我们要计算好括号里面的，再和之前的融合
                res += sign * operand # 这是计算括号里面的最后的结果，此时res是括号里面的最终计算结果
                res *= stack.pop() # 栈在之前先push的res，后sign
                res += stack.pop() # 这两句其实就是res += sign * operand
                operand = 0 # 别忘了重置，因为可能还会有剩余

        return res + sign * operand # 有剩余再计算一次即可，比如（1+2）+3，上面方法1讲了

if __name__ == "__main__":
    expression = "(1+(4+5+2)-3)+(6+8)"
    s= Solution()
    print(s.calculate(expression))


```
