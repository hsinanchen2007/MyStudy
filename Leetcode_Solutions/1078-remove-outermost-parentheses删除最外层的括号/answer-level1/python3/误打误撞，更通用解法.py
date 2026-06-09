```
class Solution:
    def removeOuterParentheses(self, S: str) -> str:
        # 定义一个列表栈，用于判断
        list1=[]
        # 定义一个保存结果的空字符串
        result = ''
        # 记录下标
        inde = 0
        for i in S:
            if not list1:
                inde = 0
            list1.append(i)
            length = len(list1)
            if i == '(':
                pass
            elif i == ')':
                if length == 2:
                    list1 = []
                    inde = 0
                elif list1.count('(')>2:
                    if list1.count(')') == list1.count('(')-1:
                        for i in range(inde):
                            result += list1.pop(1)
                            inde = 0
                    else:
                        pass
                else:
                    for i in range(inde):
                        result += list1.pop(1)
                    inde = 0
            inde+=1
        return result
```

怎么说呢，可能理解错题意，做了一种可以解当前题目又可以解另外一种题目的做法。比如S = "(((52)())(()()))"，刚看了高赞的py3答案，不适用于第二种情况。
