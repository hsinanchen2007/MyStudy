### 解题思路
三行搞定，直接拿出来转字符再拼接后再合并为数字+1，之后再还原回去就好啦

### 代码

```python3
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        s = int("".join(str(i) for i in digits))+1
        s = [int(i) for i in list(str(s))]
        return s
```