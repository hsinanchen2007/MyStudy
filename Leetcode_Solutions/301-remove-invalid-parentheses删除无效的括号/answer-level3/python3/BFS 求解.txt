本题要求的是删除**最小**无效符号后，**所有**可能的结果。
所以采用BFS搜索结果，在当前层找到所有有效的结果，即是删除最少符号的所有可能结果。
1. 初始化当前层 level=[s] 
2. 判断level内的所有元素是否满足`配对`，如果有满足`配对`的，则结束。
3. 如果不满足，则对当前level中的每个元素，依次去掉一个符号，去重，将结果作为下一个level
    例如，level=['())']时,next_level=['))','()','()']，用set去重后next_level=['))','()']

注意：
1. filter函数可用于过滤序列，过滤掉不符合条件的元素，返回符合条件元素组成的新列表
    filter(func,iterable), 其中func，返回值为:True or False, iterable为可迭代对象
    在本题中func是用于判断序列是否是配对的有效字符串，iterable是level
2. 由于输入中包含，除'()'之外的其他字符，判断函数碰到的其他字符时注意跳过




```
def isValid(s):
    stack = []
    for ss in s:
        if ss == '(':
            stack.append(ss)
        elif ss == ')':
            if len(stack)==0:
                return False
            if stack[-1] == '(':
                stack = stack[:-1]
        else:
            continue
    if len(stack) == 0:
        return True
    return False


def removeInvalidParentheses(s):
    level =[s]
    while True:
        valid = list(filter(isValid, level))
        if valid: return valid
        next_level = []
        for string in level:
            for i in range(len(string)):
                if string[i] in '()':
                    next_level.append(string[:i] + string[i + 1:])
        level = set(next_level)
```
