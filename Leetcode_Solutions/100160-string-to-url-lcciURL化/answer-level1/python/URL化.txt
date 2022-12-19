### 解题思路
1.遍历替换
2.将字符串通过split()方法转换成列表；再通过join()结合起来；
3.replace()直接替换；

### 代码

```python3
class Solution:
    def replaceSpaces(self, S: str, length: int) -> str:
        return S[0:length].replace(" ", "%20")
```