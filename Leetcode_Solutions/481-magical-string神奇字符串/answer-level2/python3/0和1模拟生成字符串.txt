根据题目规则，这种字符串可以根据自己的内容生成自己，每次的操作只有两种可能:
操作1.字符串末尾添加str[i]个1,i+1继续生成
操作2.字符串末尾添加str[i]个2,i+1继续生成

好了，可以开始生成字符串了!!!
题目已经给出了一个初始操作:添加1个1
i=0&emsp;&emsp;&emsp;添加1个1&emsp;&emsp;&emsp;"1"&emsp;&emsp;&emsp;&emsp;&emsp;i=1

这时上面的两种操作都无法进行，因为我们没有s[1]
但是事实上，如果我们上一次进行了操作1，这次只能进行操作2，反之亦然。
因为连续的相同操作会使上一处计数增加，违反规则。

所以下一步只能是 添加2个2：
i=1&emsp;&emsp;&emsp;添加2个2&emsp;&emsp;&emsp;"122"&emsp;&emsp;&emsp;&emsp;i=2

此时 s[2] = 2 所以当前操作:添加2个1
i=2&emsp;&emsp;&emsp;添加2个1&emsp;&emsp;&emsp;"12211"&emsp;&emsp;&emsp;i=3

s[3] = 1 操作:添加1个2
i=3&emsp;&emsp;&emsp;添加1个2&emsp;&emsp;&emsp;"122112"&emsp;&emsp;&ensp;i=4

...... 不断生成

为了方便书写循环的代码，不妨设初始串为"122",i=2,cur=1(当前需要添加的值)
就可以开始循环生成了~

进一步的,因为只统计1的个数,可以用1、0模拟1、2方便代码书写。
如果题目要求返回最后的字符串，也可以通过cur^=3来交替添加cur。

代码如下:
```python []
class Solution:
    def magicalString(self, n: int) -> int:
        if n==0: return 0
        magic,index,cur,res = [1,0,0],2,1,1
        while len(magic)<n: 
            magic.append(cur)
            res += cur
            if magic[index]==0 and len(magic)<n:
                magic.append(cur)
                res += cur
            cur ^= 1
            index += 1
        return res
```
时间复杂度:O(N)
空间复杂度:O(N)
感谢阅读~