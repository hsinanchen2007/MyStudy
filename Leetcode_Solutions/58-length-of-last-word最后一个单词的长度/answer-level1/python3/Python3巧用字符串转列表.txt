### 解题思路
对于s首先要进行的考虑是s中是否有字母存在。对于没有的情况用split（）函数将其转化为空列表在进行判断，而对于有的情况的话，split（）会自动去除s中的空格，并且将其转化为列表。最后返回列表最后一个元素的长度值。

### 代码

```python3
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        if s.split()==[]:
            return 0
        else:
            s=s.split()
            return len(s[-1])
        
```