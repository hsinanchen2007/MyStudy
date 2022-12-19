### 解题思路
正常做法

### 代码

```python3
class Solution:
    def toGoatLatin(self, S: str) -> str:
        temp = S.split(' ')
        ret = ''
        vowel = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
        for i in range(len(temp)):
            if i >= 1:
                ret += ' '
            if temp[i][0] in vowel:
                temp[i] += 'ma'
            else:
                temp[i]  = temp[i][1:] + temp[i][0] + 'ma'
            temp[i] += (i + 1) * 'a'
            ret += temp[i]
        return ret
```