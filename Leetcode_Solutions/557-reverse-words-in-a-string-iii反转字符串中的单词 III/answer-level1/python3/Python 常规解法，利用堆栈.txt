利用堆栈的先进后出的结构很容易做到字符反转  
但一串英文单词中，__单词的个数总是比空格的字数多一个__，在处理的时候很不方便  
如：wordA(空格)wordB(空格)wordC  
我们不妨在原字符串末尾补充一个空格，让每一小节都变成“__单词+空格__”（遇见空格就是我们判断出栈的前提条件）这样的形式  
预处理后：wordA(空格)wordB(空格)wordC(空格)  
反转后：(空格)reversed_wordA(空格)reversed_wordB(空格)reversed_wordC  
于是我们只要利用切片返回第一个字符后面的string就可以了  
```
class Solution:
    def reverseWords(self, s: str) -> str:
        s=s+" "
        stack,res=[],""
        for i in s:
            stack.append(i)
            if i==" ":
                while(stack):
                    res=res+stack.pop()
        return res[1:]
```