### 解题思路
此处撰写解题思路
![9.PNG](https://pic.leetcode-cn.com/101da6a93ef5157f9da61094c8b77db1ffcad37d546454322eb04b17040b8761-9.PNG)

### 代码

```python3
class Solution:
    def findString(self, words: List[str], s: str) -> int:
        y = -1
        try:
            y = words.index(s)
        except ValueError:
            y = -1
        return y
```