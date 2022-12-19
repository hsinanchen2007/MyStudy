
class Solution:
    def calculate(self, s: str) -> int:
        
        #计算和（或差）的函数
        def calculate(op, num1, num2):
            if op == '+':
                return num1 + num2
            return num2 - num1    #注意操作数的顺序
        
        
        #操作符和操作数出栈函数
        def op_num_stack(op_stack, num_stack):
            op = op_stack[-1]
            op_stack.pop()
            num1 = num_stack[-1]
            num_stack.pop()
            num2 = num_stack[-1]
            num_stack.pop()
            res = calculate(op, num1, num2)
            num_stack.append(res)
        
        
        #定义操作符的优先级
        rank = {'+':1, '-':1, '(':100, ')':-100}
        
        num_stack = []
        op_stack = []
        
        #循环遍历字符串：
        for i, c in enumerate(s):
            #空格情况
            if c == ' ':
                continue
            #处理数字
            if  c >= '0' and c <= '9':
                #可能是多位数的情况
                if i!=0 and (s[i-1] >= '0' and s[i-1] <= '9'):
                    num_stack[-1] = num_stack[-1] * 10 + ord(c) - ord('0')
                else:
                    num_stack.append(int(c))
            #一般操作符
            elif c == '+' or c == '-':
                while (len(op_stack) != 0) and (rank[c] >= rank[op_stack[-1]]):
                    op_num_stack(op_stack, num_stack)
                op_stack.append(c)
            #操作符是括号
            elif c == '(':
                op_stack.append(c)
            elif c == ')':
                while op_stack[-1] != '(':
                    op_num_stack(op_stack, num_stack)
                op_stack.pop()
        while len(op_stack) != 0:
            op_num_stack(op_stack, num_stack)
        return num_stack[0]