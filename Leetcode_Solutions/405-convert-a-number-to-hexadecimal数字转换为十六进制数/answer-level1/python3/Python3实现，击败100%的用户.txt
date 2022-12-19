### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def toHex(self, num: int) -> str:
        if num==0:
            return "0"
        hex, ans = "0123456789abcdef",  ""
        while num and len(ans) < 8:
            ans = hex[num & 0xf] + ans
            num >>=  4

        return ans


```