### 解题思路
此处撰写解题思路
利用set集合的特性对每个字符的每个字母进行判断,一开始老是卡在输入为空字符串报错,后来查了其他人做的添加了判断异常后就正常了.

### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        res = ''
        i = 0
        
        while True:
            try:
                a_list = []
                for each in strs:
                    a_list.append(each[i])
                
                if len(set(a_list)) == 1:
                    res = res + a_list.pop()
                    i += 1
                else:
                    break
            except Exception as e:
                break
        
        return res

```