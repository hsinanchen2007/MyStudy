```
class Solution(object):
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        s = s + '='           
        num = 0
        ops = ['+']
        if s[0] == '-':
            s = '0' + s
        nums = [0]
        n = 0
        i = 0
        c1 = s[0]
        while i<len(s):
            if s[i] == ' ':
                pass
            elif s[i] in '+-*/()=':
                op = s[i]
                #print('+-*/()+before',  'op',op, 'nums', nums, 'ops', ops)
                if op in '+-)=':
                    n = nums.pop()
                    num = nums.pop()
                    op1 = ops.pop()
                    if op1 == '+':
                        num += n
                    elif op1 == '-':
                        num -= n
                    elif op1 == '*':
                        num *= n
                    elif op1 == '/':
                        num /= n
                    else: # (
                        ops.append('(')
                        nums.append(num)
                        #print('------------------------------------', op1, op)
                        num = n
                    if op == ')':
                        if op1 == '(':
                            nums.append(num)
                            ops.pop() # pop(
                        else:
                            nums.append(num)
                            #ops.append(op)
                            continue            
                    elif op == '=':
                        if ops:
                            nums.append(num)
                            continue
                        break
                    else:
                        if ops and ops[-1] in '+-*/)':
                            nums.append(num)
                            continue
                        nums.append(num)
                        ops.append(op)
                elif op in '*/':
                    op1 = ops[-1]
                    if op1 in '*/':
                        n = nums.pop()
                        num = nums.pop()
                        op1 = ops.pop()
                    if op1 == '*':
                        num *= n
                        nums.append(num)
                    elif op1 == '/':
                        num /= n
                        nums.append(num)
                    ops.append(op)
                elif op == '(':
                    ops.append(op)
                    j = i+1
                    while s[j] == ' ':
                        j += 1
                    if s[j] == '-':
                        nums.append(0)
                n = 0
            elif s[i].isnumeric():
                n = n*10 + int(s[i])
                if i+1>=len(s) or not s[i+1].isnumeric():
                    nums.append(n)
                    #print("append", n)
            i += 1
        return num

```
