### 解题思路
此处撰写解题思路
set的交集操作
### 代码

```python3
class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        colu1=set('qwertyuiop')
        colu2=set('asdfghjkl')
        colu3=set('zxcvbnm')
        str_list=[]
        for str in words:
            str_temp=set(str.lower())
            if str_temp&colu1==str_temp or str_temp&colu2==str_temp or\
                    str_temp&colu3==str_temp:
               str_list.append(str)
        return str_list
                
```