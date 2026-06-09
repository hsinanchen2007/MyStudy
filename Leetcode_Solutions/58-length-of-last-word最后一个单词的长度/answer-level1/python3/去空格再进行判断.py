### 解题思路
先去掉首尾空格,然后再利用空格进行字符串分割,将字符串转换成list,最后返回长度就行了.

### 代码

```python3
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s=s.strip()
        s=s.split(" ")
        List=s[-1]
        List=list(List)
        return len(List)
```