### 解题思路
模仿发牌过程:
s为一副扑克牌，
str_list用于生成若干个玩家，
get_index用于指定给谁发牌。

### 代码

```python3
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        def get_index(numRows):
            while True:
                for i in range(numRows):
                    yield i
                for i in range(numRows-2,0,-1):
                    yield i
        str_list = ['' for i in range(numRows)]
        index = get_index(numRows)
        for i in s:
            str_list[next(index)] += i
        result = ''.join(str_list)
        return result

```