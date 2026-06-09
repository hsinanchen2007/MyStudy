### 解题思路
###此处撰写解题思路
菜鸟
先建立键值对为右括号-左括号的字典，和值为左括号的列表
然后将输入字符串转为列表
通过对列表中的元素进行逐个取出比对。
### 代码

```python3
one_dict = {')':'(',']':'[','}':'{'}
two_list =['(','{','[']
class Solution:
    def isValid(self, s: str) -> bool:
        tag = 0
        left_list =[]
        str_list = [value for value in s]
        if str_list :
            for _ in str_list:
                if _ in two_list:
                    left_list.append(_)
                    tag = tag + 1
                elif left_list and (one_dict[_] == left_list[-1]):
                    left_list.pop()
                    tag = tag -1
                else:
                    return False
            if tag == 0:
                return True
        elif s == "":
            return True
        else:
            return False
```