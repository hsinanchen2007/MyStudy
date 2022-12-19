### 解题思路
我的想法是：
1. int和str相互转换。
2. str转入list中。
3. 将list反转。
4. 将list转str。
### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        a=str(x)
        a=a+" "
        if a[0]=="-":
            b=a[1:-1]
            c=[]
            for i in range(len(b)):
                c.append(b[i])
            c.reverse()
            c.insert(0,"-")
            d=c[0]
            for j in range(1,len(c)):
                d=d+c[j]
            if int(d)<-2**31:
                return 0
            return int(d)
        else:
            e=[]
            for k in range(len(a)):
                e.append(a[k])
            e.reverse()
            f=e[0]
            for h in range(len(e)):
                f=f+e[h]
            if int(f)>2**31-1:
                return 0
            return int(f)



```