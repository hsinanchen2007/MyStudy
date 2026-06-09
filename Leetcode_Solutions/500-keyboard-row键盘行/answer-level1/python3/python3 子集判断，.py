

看了大家的代码，有的很好，我也写了一个


`内联代码

    class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        #use set
        a=set("qwertyuiop")
        b=set("asdfghjkl")
        c=set("zxcvbnm")
        #a = {'q','w','e','r','t','y','u','i','o','p'}
         # b = {'a','s','d','f','g','h','j','k','l'}
               # c = {'z','x','c','v','b','n','m'}

        res=[]
        for i in words:
            save=i
            i=i.lower()
            if set(i).issubset(a) or  set(i).issubset(b) or set(i).issubset(c) :
                   res.append(save) 
        return res
`

粘贴代码，总是有对齐的问题，各位哥哥指导我 