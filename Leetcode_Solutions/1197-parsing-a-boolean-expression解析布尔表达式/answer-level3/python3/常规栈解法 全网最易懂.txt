```
class Solution:
    def parseBoolExpr(self, expression: str) -> bool:
        arr=[]
        for x in expression:           # 倒序记录exp，除掉‘,’，将tf换成布尔值
            if x==',':
                continue
            elif x=='t':
                arr.append(True)
            elif x=='f':
                arr.append(False)
            else:
                arr.append(x)

        b=[]                            # b用于记录‘)’和将用于计算和计算完毕的布尔变量
        while len(arr)>0 or len(b)!=1:  # 当arr=None且b只有一个变量时跳出循环
            x=arr.pop()
            if x=='(':                  # 倒序遍历exp，遇到‘(’，则下一个必定是运算符op
                op=arr.pop()            # 运算符op从arr出栈，而布尔变量从b出栈
                x=b.pop()
                if op=='!':
                    res=not x
                    x=b.pop()           # 由于‘!’取非后面必定只有一个布尔变量，所以要把多余的‘)’顶出栈b
                if op=='&':
                    res=True            # 真并x=x（True不会改变x的布尔值）
                    while x!= ')':      # 当op为并、或时需要连续出栈操作
                        res=res and x
                        x=b.pop()
                if op=='|':
                    res=False           # 假或x=x（同上）
                    while x!= ')':
                        res=res or x
                        x=b.pop()
                x=res                   # res覆盖x，因为x覆盖前=运算结束后多余的‘)’符号，要除掉
            b.append(x)                 # 将运算结果或者还没遇到op的布尔变量和分隔符‘)’入栈b
        return b.pop()                  # 当栈b只剩一个变量时，就是最终答案
```
