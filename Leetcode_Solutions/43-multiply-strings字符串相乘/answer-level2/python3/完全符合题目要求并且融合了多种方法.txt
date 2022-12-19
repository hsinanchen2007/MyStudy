没有使用int
有查找表，分界点，大数加法
```
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        
        num1=num1[::-1]
        num2=num2[::-1]
        base_ord=ord('0')
        if len(num1)*len(num2)<300:
            # 乘法次数少直接算。全用这个208 ms
            s=0
            for i1,n1 in enumerate(num1):
                for i2,n2 in enumerate(num2):
                    s+=((ord(n1)-base_ord)*(ord(n2)-base_ord))*10**(i1+i2)
            return str(s)
        else:
            # 太长了，经常重复乘法，用查找表。全用这个要272ms，初始化需要100次乘法。
            nine_nine=dict((str(i),
            dict((str(j),i*j) for j in range(10))
            ) for i in range(10))
            #
            ans=[0]*(len(num1)+len(num2)+1)
            for i1,n1 in enumerate(num1):
                for i2,n2 in enumerate(num2):
                    i=i1+i2
                    # 取出来
                    product=nine_nine[n1][n2]              
                    # 存回去
                    carry=0
                    while product or carry:
                        ans[i]=product%10+ans[i]+carry
                        product//=10
                        if ans[i]>9:
                            carry=ans[i]//10
                            ans[i]=ans[i]%10
                        else:
                            carry=0
                        i+=1
                    # print(cache,product,ans)
            # 去0
            for i in range(len(ans)-1,-1,-1):
                if ans[i]==0:
                    ans.pop(i)
                else:
                    break
            if not ans: return '0'
            ans=[str(a) for a in ans[::-1]]
            return ''.join(ans)

```
