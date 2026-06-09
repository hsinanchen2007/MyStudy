### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def removeKdigits(self, num, k):
        """
        :type num: str
        :type k: int
        :rtype: str
        """
        stack=[]
        result=''
        if k>=len(num):
            return '0'
        for n in num:
            n=int(n)+0
            while(len(stack)>0 and stack[-1]>n and k>0):
                # if(len(stack)==1 and n==0):
                #     break
                stack.pop()
                #stack.append(num)
                k-=1
                #print(k)
            #if(n!=0 or len(stack)>0):
            stack.append(n)
                #print(stack)
        while(k>0):
            stack.pop()
            k-=1
        flag=1
        for i in stack:
            if flag==1:
                if i!=0:
                    result+=str(i)
                    flag=0
                else:
                    continue
            else:
                result+=str(i)
        if len(result)==0:
            return '0'
        return result
```