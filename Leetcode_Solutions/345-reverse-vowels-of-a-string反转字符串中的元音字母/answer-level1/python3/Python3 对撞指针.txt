### 解题思路
大写也放进判断字符串里，比再调用 s[i].lower()转成小写来判断快很多。

### 代码

```python3
class Solution:
    def reverseVowels(self, s: str) -> str:
        
        i , j = 0 , len(s) - 1
        sample = 'aeiouAEIOU'
        lst =list(s)
        while i < j:
            if lst[i] not in sample:
                i += 1
                continue
            if lst[j] not in sample:
                j -= 1      
                continue
            
            lst[i] , lst[j] = lst[j] , lst[i]
            i += 1
            j -= 1
        return ''.join(lst)
        
```