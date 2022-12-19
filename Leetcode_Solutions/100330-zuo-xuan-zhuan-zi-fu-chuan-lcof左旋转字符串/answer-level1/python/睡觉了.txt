### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def reverseLeftWords(self, s, n):
        """
        :type s: str
        :type n: int
        :rtype: str
        """
        sl = list(s)
        self.reverseWord( sl , 0 , n-1) 
        self.reverseWord( sl , n , len(sl)-1)
        self.reverseWord( sl , 0 , len(sl)-1)
        return "".join(sl)

    def reverseWord(self , s , i ,j ):
        while i < j :
            temp = s[i]
            s[i] =  s[j]
            s[j] = temp
            i += 1
            j -= 1
```