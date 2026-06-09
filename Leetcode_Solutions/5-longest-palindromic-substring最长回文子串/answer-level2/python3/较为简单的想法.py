解法为遍历寻找回文字符串最中间的两个（如：bb）或三个（如：bab）字母，然后逐步向两边展开，最后由left和right划定回文字符串，left和right初始圈定第一个字母。

由于涉及到index，index+1，index+2的比较，所以要注意字符串长度为1,2或者3的情况和index越界的情况。
Python3代码：
```
class Solution:
    def longestPalindrome(self, s: str) -> str:
        left=0
        right=1
        longest=1
        index=0     
        while index<len(s):    
            if len(s)==1 or index>=len(s)-1:
                break
            if s[index]==s[index+1]:
                long=2
                length=1
                while index-length>=0 and index+1+length<len(s):
                    if s[index-length]==s[index+1+length]:
                        long+=2
                        length+=1
                    else:
                        break
                if longest<long:
                            longest=long
                            left=index-length+1
                            right=index+1+length
            if len(s)==2 or index>=len(s)-2:
                break
            if s[index]==s[index+2]:
                long=3
                length=1
                while index-length>=0 and index+2+length<len(s):
                    if s[index-length]==s[index+2+length]:
                        long+=2
                        length+=1
                    else:
                        break
                if longest<long:
                            longest=long
                            left=index-length+1
                            right=index+2+length
            index+=1

        return s[left:right]
```