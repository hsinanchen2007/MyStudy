1. 递归
```
class Solution:
    def reverseString_v0(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        # recursion, but the recursion depth exceede
        def recur(tmps: List[str]) -> str:
            if len(tmps)<=1:
                return tmps
            else:
                return recur(tmps[1:])+[tmps[0]]
        s[:] = recur(s)
```
内存溢出

2. 双指针
```
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        # double pointer
        i,j = 0,len(s)-1
        while i<j:
            s[i],s[j] = s[j],s[i]
            i+=1;j-=1
```
执行用时：288 ms
3. 一步法
```
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        # one step by python
        s[:] = s[::-1]
```
执行用时：348 ms

4. 递归+双指针
```
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        # double pointer and recursion
        def recur_(s, i,j):
            if i>=j:
                return 
            else:
                s[i],s[j] = s[j],s[i]
                recur_(s,i+1,j-1)
        recur_(s,0,len(s)-1)
```
执行用时：252 ms

[Aunity](https://github.com/Aunity)