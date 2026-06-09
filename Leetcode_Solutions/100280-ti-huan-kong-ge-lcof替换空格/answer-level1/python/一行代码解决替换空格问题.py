使用Python中的replace（）函数

str.replace(old, new[, max]) ，Python replace() 方法把字符串中的 old（旧字符串） 替换成 new(新字符串)，
如果指定第三个参数max，则替换不超过 max 次

```python3
class Solution:
    def replaceSpace(self, s: str) -> str:
    
        return s.replace(" ", "%20")

        