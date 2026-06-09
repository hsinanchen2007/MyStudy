### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def nextGreatestLetter(self, letters, target):
        for i in letters:
            if ord(i)>ord(target):
                return i

        return letters[0]
```