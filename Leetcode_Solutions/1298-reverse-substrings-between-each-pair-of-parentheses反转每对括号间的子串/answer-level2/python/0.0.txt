### 解题思路
用一下栈

### 代码

```python3
class Solution:
    def reverseParentheses(self, s: str) -> str:
        def reverse(s):
            s=list(s)
            s.reverse()
            s_tmp=[]
            while(len(s)):
                itm= s.pop()
                #print(itm)
                if itm !=')':
                    s_tmp.append(itm)
                else: 
                    new_tmp=[]   
                    while(1):                           
                        dat=s_tmp.pop()
                        if dat !='(':
                            new_tmp.append(dat) 
                            #print(dat,s,s_tmp)
                        else :
                            for i in range(len(new_tmp)):
                                itm=new_tmp.pop()
                                s.append(itm)
                            break
            #s_tmp.reverse()
            return (''.join(s_tmp))
        return reverse(s)
```