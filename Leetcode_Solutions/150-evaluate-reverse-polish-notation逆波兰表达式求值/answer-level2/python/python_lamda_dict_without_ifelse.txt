```
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        operator={'+':lambda x1,x2:x1+x2,'-':lambda x1,x2:x1-x2,'*':lambda x1,x2:x1*x2,'/':lambda x1,x2:int(x1/float(x2))}
        for item in tokens:
            if item not in operator:
                stack.append(int(item))
            else:
                operator_num1=stack.pop()
                operator_num2=stack.pop()
                operator_res=operator[item](operator_num2,operator_num1)
                stack.append(operator_res)
        return stack[0]
```
