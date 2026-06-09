### 解题思路
首先判断输入字符是否为0，如果是，返回0（很重要！否则提交不通过！）
然后利用字符串截取反转，最后再转换成整形（自动去开头的0）
### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        if x == 0:
            return 0
        y = int(str(x)[::-1]) if x>0 else -int(str(x)[:0:-1])
        return y if -2**31<y<2**31-1 else 0
```