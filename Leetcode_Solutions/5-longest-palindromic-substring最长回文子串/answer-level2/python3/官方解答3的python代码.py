```
class Solution:
    def longestPalindrome(self, s: str) -> str:
        # 找寻所有的一字回文和二字回文
        # single = []
        # double = []
        myList = []
        n = len(s)
        if n == 0:
            return ''
        # 一字回文
        for ii in range(n):
            myList += [[ii, ii+1]]
        # 二字回文
        for ii in range(n-1):
            if s[ii] == s[ii+1]:
                myList += [[ii, ii+2]]
        # 对回文进行扩展
        # buffer = myList
        while True:
            container = []
            for index in myList:
                if index[0]-1 >= 0 and index[1] < n:
                    if s[index[0]-1] == s[index[1]]:
                        container += [[index[0]-1, index[1]+1]]
            if container:
                myList = container
            else:
                break
        return s[myList[-1][0]:myList[-1][1]]
```
