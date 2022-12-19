### 解题思路
此处撰写解题思路
就是最基础的字符串操作。
### 代码

```python3
class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        num=0
        for char in J:
            num+=S.count(char)
        return num
```