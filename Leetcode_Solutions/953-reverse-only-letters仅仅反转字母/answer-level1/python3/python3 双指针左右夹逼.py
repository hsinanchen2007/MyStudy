### 解题思路
时间复杂度：O(len(S))，双指针遍历列表一遍即可
空间复杂度：O(len(S))，由于python中字符串S不可以原地修改，只能另存为列表l，长度为len(S)

### 代码

```python3
class Solution:
    def reverseOnlyLetters(self, S: str) -> str:
        l=list(S)
        i=0
        j=len(S)-1
        while i < j:
            while i < j and not l[i].isalpha():
                i+=1
            while i < j and not l[j].isalpha():
                j-=1
            l[i],l[j]=l[j],l[i]
            i+=1
            j-=1
        return ''.join(l)
```