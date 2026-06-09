核心思想，使用位运算，每4位，对应1位16进制数字。

- 使用0xf(00...01111b)获取num的低4位。
>>算数位移，其中正数右移左边补0，负数右移左边补1。
- 位移运算并不能保证num==0，需要使用32位int保证（对应16进制小于等于8位).

使用string直接进行字符串拼接....

```python
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

