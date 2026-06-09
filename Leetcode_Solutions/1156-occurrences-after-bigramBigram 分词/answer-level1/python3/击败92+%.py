### 解题思路
两边加入‘ ’是为了避免aa of apple 输入为 a of 情况。

### 代码

```python3
class Solution:
    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
        res=[]
        index=0
        text=' '+text
        string=' '+first+' '+second+' '
        length=len(string)
        while text.find(string)!=-1:
            index=text.find(string)
            text=' '+text[index+length:]
            if text:
                res.append(text.split(' ',2)[1])
            else:
                break
        return res


```