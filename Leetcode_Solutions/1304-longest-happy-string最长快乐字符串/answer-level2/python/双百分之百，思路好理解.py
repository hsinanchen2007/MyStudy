
![image.png](https://pic.leetcode-cn.com/f78b62a6d81f021e6cbca9306c2ea886f7f496bff1df0a0fc34d24195cb9b080-image.png)

主要思路就是一个一个往里面填，找最大值依次往里面填，如果碰到末尾两个一样的那就在另外两个字母中找寻最大值。
```
class Solution(object):
    def longestDiverseString(self, a, b, c):
        res=[]
        #下面这几行就是h=max(a,b,c)情急之下没找函数因为这个函数记录不了位置
        if a>=b and a>=c:
            h=a
            m='a'
        elif b>=a and b>=c:
            h=b
            m='b'
        elif c>=a and c>=b:
            h=c
            m='c'
        #到这里
        while True:
            if h==0:
                break
            #==0就代表没有剩余规定内字母
            #往里面填a
            if m=='a':
                res.append('a')
                a-=1
                
                if res[-2:]==['a','a']:
                    #下面这几串就是h=max(b,c)，在b，c中找
                    if b>c:
                        m='b'
                        h=b
                    else:
                        m='c'
                        h=c
                else:
                    #下面这几串就是h=max(a,b，c)，在a，b，c中找，因为末尾没有2个重复字母
                    if a>=b and a>=c:
                        h=a
                        m='a'
                    elif b>=a and b>=c:
                        h=b
                        m='b'
                    elif c>=a and c>=b:
                        h=c
                        m='c'  
            #往里面填b            
            elif m=='b':
                res.append('b')
                b-=1
                if res[-2:]==['b','b']:
                    #h=max(a,c)下面几行
                    if a>c:
                        m='a'
                        h=a
                    else:
                        m='c'
                        h=c
                else:
                    #h=max(a,b,c)下面几行
                    if a>=b and a>=c:
                        h=a
                        m='a'
                    elif b>=a and b>=c:
                        h=b
                        m='b'
                    else:
                        h=c
                        m='c' 
            #往里面填c
            elif m=='c':
                res.append('c')
                c-=1
                if res[-2:]==['c','c']:
                    #h=max(a,b)
                    if a>b:
                        m='a'
                        h=a
                    else:
                        m='b'
                        h=b
                else:
                    #h=max(a,b,c)
                    if a>=b and a>=c:
                        h=a
                        m='a'
                    elif b>=a and b>=c:
                        h=b
                        m='b'
                    else:
                        h=c
                        m='c' 
                    
        l=''.join(res)
        return l
```
