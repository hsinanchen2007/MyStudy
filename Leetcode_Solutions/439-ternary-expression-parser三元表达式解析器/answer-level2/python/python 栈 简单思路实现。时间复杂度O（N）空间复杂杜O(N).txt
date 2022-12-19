我写了一个更简单的。
执行用时 : 84 ms , 在所有 Python 提交中击败了 17.65% 的用户
内存消耗 : 13.1 MB , 在所有 Python 提交中击败了 100.00% 的用户

T?T?F?7:T?T?F?3:**F?0:0**:6:1:0:5

```py
class Solution(object):
    def parseTernary(self, expression):
        """
        :type expression: str
        :rtype: str
        """
        stack = []  # 从右到左遍历 将没有匹配计算的内容 压入栈中
        flag = 0  # 用于标记是否找到了一个完成的？：运算符
        for i in range(len(expression) - 1, -1, -1):
            if flag:  # 如果刚刚 找到了一个三目运算符，则需要 跳过一次下面的判断（使用continue实现）。
                flag = 0
                continue
            cur = expression[i]  # 当前符号
            if cur != "?":
                stack.append(cur)
            else:  # 如果是 ？ 则说明，需要出栈计算一次三目运算
               
                pre = expression[i-1]
                a = stack.pop()
                _ = stack.pop()
                b = stack.pop()

                res_temp = a if pre == "T" else b  # 计算三目运算
                 
                flag = 1
                stack.append(res_temp)  # 三目运算 计算之后 变成一个字符 压栈，同时标记flag为1，
                # 用于跳过已经使用过的 pre = expression[i-1] 
                
                # print("stack = ", stack[::-1])
        return stack[0]
        
```
