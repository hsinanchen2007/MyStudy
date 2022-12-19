![image.png](https://pic.leetcode-cn.com/c4d6aba491f15bce9abba332e4e0a478445bf6d7c4b09bba0886425caf60a3a9-image.png)

唯一要注意的是算除法时不能用整除‘//’，否则出现负数时不会得到你想要的答案，比如说（6//-132）会得到（-1），是向下取整的答案。

python数组不分类型，所以在录入数字的时候就可以直接整型化了，避免多余字符数字转换。

因为数据的问题，加减乘除的判断顺序有可能会影响速度。

```
class Solution:
    def evalRPN(self, t: List[str]) -> int:
        d=[]
        n=len(t)
        for i in range(n):
            if '0'<=t[i][-1]<='9':#元素的最后一位是数字，那元素一定是数字
                d+=[int(t[i])]
            else:
                if t[i]=='/':
                    d[-2]=int(d[-2]/d[-1])
                elif t[i]=='*':
                    d[-2]*=d[-1]
                elif t[i]=='-':
                    d[-2]-=d[-1]
                elif t[i]=='+':
                    d[-2]+=d[-1]
                d.pop()
        return d[0]
```

还有种更直接的eval算法，就是太慢，时间只有5%左右，时间主要耗费在元素类型转换上了

```
class Solution:
    def evalRPN(self, t: List[str]) -> int:
        d=[]
        n=len(t)
        for i in range(n):
            if '0'<=t[i][-1]<='9':
                d+=[t[i]]
            else:
                d[-2]=str(int(eval((d[-2]+t[i]+d[-1]))))
                d.pop()
        return int(d[0])
```
