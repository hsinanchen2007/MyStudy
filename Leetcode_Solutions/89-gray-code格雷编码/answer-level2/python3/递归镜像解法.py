结果正确，执行用时超**95%**的同学。
首先通过写一两组案例就可以发现这是一个镜像问题，如
0：000
1：001
3：011
2：010
6：110
7：111
5：101
4：100
观察上面的八个数字，可以发现地i个和地i+4个相差4，也就是相差2^（k-1），这里k是指二进制位数，
令s表示该数组的第i个数，上面的形式用二进制处理起来就是
**s[i+2^（k-1）] = s[i] | (1 << k-1)**，
如 110 = 010 | 100
   111 = 011 | 100
   101 = 001 | 100
   100 = 000 | 100
对上面的运算进行递归即可。

```python
class Solution:
    #用于递归计算数组，其中[0,1]换成[1,0]也可以
    def addpre(self, k):
        if k == 1:
            return [0,1]
        else:
            #add表示镜像时加在前面的1，即10000...(k-1个0)
            add = 1 << k-1
            add_list = self.addpre(k-1)
            for i in range(2**(k-1)-1,-1,-1):
                #公式**s[i+2^（k-1）] = s[i] | (1 << k-1)**
                new = add | add_list[i]
                add_list.append(new)
        return add_list
    def grayCode(self, n: int) -> List[int]:
        if n == 0:
            return [0]
        else:
            return self.addpre(n)           
```
