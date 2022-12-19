### 解题思路
浓缩才是精华

### 代码

```python3
class Solution(object):
    def plusOne(self, digits):
        return [int(i) for i in str(int(''.join([str(i) for i in digits])) + 1)]
```