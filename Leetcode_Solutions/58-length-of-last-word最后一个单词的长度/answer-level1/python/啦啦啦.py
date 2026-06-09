### 解题思路
python就是很好的文字处理软件啊，哈哈哈

### 代码

```python
class Solution(object):
    def lengthOfLastWord(self, s):
        s=s.split(' ')[::-1];
        for a in s:
            if a!='':
                return len(a)
        return 0
```