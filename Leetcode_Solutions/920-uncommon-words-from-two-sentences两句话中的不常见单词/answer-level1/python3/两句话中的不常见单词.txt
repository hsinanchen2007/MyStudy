### 解题思路
将字符串A，B用split方法拆分为单词列表，组成一个新列表lt，将列表lt转换为字典dt，列表元素为key，值为0，因为字典key唯一，遍历字典每一个key在lt中的数量，数量为1的即是不重复的

### 代码

```python3
class Solution:
    def uncommonFromSentences(self, A: str, B: str) -> List[str]:
        lt=A.split(' ')
        lt.extend(B.split(' '))
        dt={x:0 for x in lt}
        lt1=[key for key in dt.keys() if lt.count(key)==1]
        return lt1

```