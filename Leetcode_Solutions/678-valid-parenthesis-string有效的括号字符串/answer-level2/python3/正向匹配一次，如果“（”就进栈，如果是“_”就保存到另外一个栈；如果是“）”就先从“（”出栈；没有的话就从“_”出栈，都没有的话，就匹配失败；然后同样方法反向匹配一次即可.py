### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def checkValidString(self, s: str) -> bool:
        left_list = []
        xing_list = []
        right_list = []
        for i in s:
            if i == "(":
                left_list.append(i)
            elif i == "*":
                xing_list.append(i)
            else:
                if len(left_list) > 0:
                    left_list.pop(-1)
                else:
                    if len(xing_list) > 0:
                        xing_list.pop(-1)
                    else:
                        return False
        if len(xing_list) < len(left_list):
            return False
        xing_list = []
        for i in ''.join(reversed(s)):
            if i  == ")":
                right_list.append(i)
            elif i == "*":
                xing_list.append(i)
            else:
                if len(right_list) > 0:
                    right_list.pop(-1)
                else:
                    if len(xing_list) > 0:
                        xing_list.pop(-1)
                    else:
                        return False
        if len(right_list) > len(xing_list):
            return False
        return True






```