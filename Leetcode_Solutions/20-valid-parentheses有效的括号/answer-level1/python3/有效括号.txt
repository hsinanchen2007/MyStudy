### 解题思路
1、确定此题的处理逻辑是关键，剩下的就是编码问题了
2、有效的括号组合，一定具有如下特征：给定字符串的第一个右括号类似"]""}"")",则它的前一个字符必定是其有效组合的左括号
3、将符合第二步的有效括号删除
4、再次进行循环
5、主体逻辑如上

### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        zidian1 = {')':'(',']':'[','}':'{'}
        lists = list(s)
        flag = 'bb'
        i = 0
        while lists:
            try:
                lists[i]
            except IndexError:
                return(False)
            num1 = len(lists)
            if lists[i] in zidian1:
                if lists[i-1] and lists[i-1] == zidian1[lists[i]]:
                    del lists[i]
                    del lists[i-1]
                    i -= 1
                else:
                    return(False)
                    flag = 'xx'
            else:
                i += 1
                if i >= num1:
                    flag = 'xx'
                    return(False)
        if flag == 'bb':
            return(True)

```