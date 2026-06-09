字符串解法（看代码直接最下边，当然不太规范，凑活看）
首先分析规律：对于一个位数大于3的数，如a = 5342625
长度为len(a)
那么它的解应为：5*10**(len(a)-1)的解+3*10**(len(a)-2)+....
这样我们就转化为求除第一位不为0其它位都为0的数的解，则有以下规律：
当首位为1时
num      answer
100       21
1000      301
10000     4001
....
规律为(len(num)-1)*10**(len(a)-2)+1
当首字母不为1时，稍稍复杂
num      answer
10000    4001
20000    18000
30000    22000
40000    26000
...
规律出现了，20000的解为((len(num)-1)*2+10)*10**(len(num)-2)
而比20000大的num，则依次比20000的解(len(num)-1)*10**(len(num)-2)
可能有些凌乱，总之是先找到1000、10000、100000...的解的规律,再找到100000、200000、300000...的规律
当然这还差一些，举例
5123553，当分解到2时，因为其前一位为1，所以需要在结果基础上加上（123553-100000）
此外分解到百位数停止，再加上最后两位数的解，对此例来说就是分解到百分位的5停下，加上53的解
```{python3}
class Solution:
    def countDigitOne(self, n: int) -> int:
        if n<1:
            return 0
        if n<10:
            return 1
        else:
            n_ = list(str(n))
            index = len(n_)
            time = 0
            for i in range(1,index-1):
                k = int(n_[i-1])
                index_ = index-i+1
                if k==0:
                    if n_[i-2]=='1':
                        time +=int(''.join(n_[i-2:]))-10**(len(n_[i-2:])-1)
                    continue
                if k==1:
                    if n_[i-2]=='1':
                        time +=int(''.join(n_[i-2:]))-10**(len(n_[i-2:])-1)
                    time+= int((index_-1)*10**(index_-2)+1)
                else:
                    if n_[i-2]=='1':
                        time +=int(''.join(n_[i-2:]))-10**(len(n_[i-2:])-1)
                    u = index_-2
                    time+= int(((index_-1)*2+10)*10**(index_-2)+(k-2)*(index_-1)*10**u)
            if len(n_)>=3 and n_[-3]=='1':
                time+=int(n_[-2]+n_[-1])
            count = 0
            for i in range(1,int(n_[-2]+n_[-1])+1):
                for j in list(str(i)):
                    if j=='1':
                        count+=1
            return time+count
```

