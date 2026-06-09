### 解题思路
两种解法，第一种是利用sort（）和find（）函数，借鉴了题解中的大神思路；第二种是sort（）排序加双指针，用时更短

### 代码

```python3
class Solution:
    def findLongestWord(self, s: str, d: List[str]) -> str:
        
        '''
        l = 0
        longestword = []
        a = 0
        b = 0
        for word in d:
            a

            if set(word).issubset(set(s)) and len(word) >= l:
                if len(word) == l:
                    longestword = sorted([word,longestword])[0]
                else:
                    longestword = word
                l = len(word)
        return longestword
        '''
        # pythonic
        d.sort(key = lambda x: [-len(x), x])  #key  = [-len(x), x] x指传入的参数
        def f(c):
            i = 0
            for letter in c:
                k = s.find(letter, i)
                if k == -1:
                    return False
                i = k + 1
            return True
        
        for c in d:
            if f(c):
                return c 
        return ''

        #双指针
        d.sort(key = lambda x: [-len(x), x])
        for word in d:
            a = 0
            b = 0
            while a < len(s) and b < len(word):
                if s[a] == word[b]:
                    a += 1
                    b += 1
                else:
                    a += 1
            if len(word) == b:
                return word
        return ''

            

```