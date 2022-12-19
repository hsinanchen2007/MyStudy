思路：直接用字符的count方法统计个数，对于连续的情况，判断一下连续的情况是否存在就行
```
if s.count('A')>1 or 'LLL' in s:  
            return False
        return True
```
