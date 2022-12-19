### 解题思路
要找最大絕對不會把9轉成6
用python的str.replace()方法把6改成9 設定最大次數不得超過1次
### 代码

```python3
class Solution:
    def maximum69Number (self, num: int) -> int:
        return int(str(num).replace("6", "9", 1))
```