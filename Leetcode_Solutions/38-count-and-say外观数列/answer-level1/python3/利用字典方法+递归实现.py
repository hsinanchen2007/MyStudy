```
class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return '1'
        return self.qiuhe(self.countAndSay(n-1))

    def qiuhe(self,c:str):
        a={'111':31,'222':32,'33':23,'22':22,'11':21,'1':11,'2':12,'3':13,'0':5}
        d=c+'00'  
        n=[d]
        b=[]
        i=0
        while i <len(n[0])-2:
                if n[0][i]==n[0][i+1]:
                        if n[0][i+1]==n[0][i+2]:
                            b.append(a[n[0][i:i+3]])
                            i+=3
                        else:
                            b.append(a[n[0][i:i+2]])
                            i+=2
                else:
                    b.append(a[n[0][i]])
                    i+=1
        b=[str(i) for i in b]
        c=''.join(b)
        return c
```
最开始想到就是利用字典实现，虽然这样看起来有一些复杂，但是感觉也挺好理解的，大概与其他人的想法都不太一样，不懂的地方可以提问
![038.png](https://pic.leetcode-cn.com/bd282f3639ed86350e7411340d41b07f9c9c82639795c6a7848c0c06e61968b1-038.png)


