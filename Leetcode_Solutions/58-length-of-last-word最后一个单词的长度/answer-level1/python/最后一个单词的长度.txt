小菜鸟。查了一下python自带的函数，发现python自带函数好适合这道题啊，自己之写的好智障
```
class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        if s=='':
            ans=0
        elif s.isspace():
            ans=0
        else:
            s=s.split()
            ans=len(s[-1])
        return ans
```

执行用时 : 16 ms, 在Length of Last Word的Python提交中击败了97.49% 的用户
内存消耗 : 12 MB, 在Length of Last Word的Python提交中击败了11.43% 的用户