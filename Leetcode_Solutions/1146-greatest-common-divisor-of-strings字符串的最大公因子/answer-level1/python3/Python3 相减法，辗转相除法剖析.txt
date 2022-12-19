两种方法首先都要利用两个字符串相加相等来排除字符串含有多余子串的情况。
接下来我们分别来看这两种方法的原理及应用。
# **相减法**
有两整数a和b：

1.若a>b，则a=a-b

2. 若a<b，则b=b-a

3. 若a=b，则a（或b）即为两数的最大公约数

4. 若a≠b，则再回去执行1
————（参考CSDN 沉默晨晨）
其数学原理可以理解为先假设a,b有一个最大公因数T，用长的字符串减去短的字符串，则T一定存在于这个多余部分内。
反复进行，最后一定可以得到T。
```
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if str1+str2!=str2+str1:
            return ''
        dif=len(str1)-len(str2)
        if dif==0:
            return str1
        elif dif>0:
            return self.gcdOfStrings(str1[len(str2):],str2)
        else:
            return self.gcdOfStrings(str1,str2[len(str1):])
```
# **辗转相除法**

有两整数a和b：

1.a%b得余数c

2.若c=0，则b即为两数的最大公约数

3. 若c≠0，则a=b，b=c，再回去执行1
————（参考CSDN 沉默晨晨）
从第一种视角看辗转相除法，其本质是和相减法是一致的。
比如a=T,T,T,T,T b=T,T
相减法
第一次操作后 a=T,T,T b=T,T
第二次操作后 a=T b=T,T
第三次操作后 a=T b=T
辗转相除法
第一次操作 5/2=2...1
第二次操作 2/1=2...0
相除实际上可以理解为一次将所有a中大于b的长度部分移除，也就是说相减法中的1，2直接被辗转相除法中的1代替
我们再看可以除尽的情况
可以除尽的话意味着没有余数，这和相减法中最后a=b实际上是一致的

第二种视角
a=k1*b+c
b=k2*c+d
c=k3*d
说明两点：
1.为什么得到的d会是a,b公因数
b是c的（k2*k3+1）倍,a是c的（（k2*k3+1）*k1+1）倍
实际上还可以继续往下循环，总能保证a,b是最后那个数（本例中的d）的线性倍
2.为什么每次除都可以保证没有比余数更大的公因数可能
假设存在一个比余数更大的公因数t
例如a=45 b=20
a=9*5 b=4*5 此时t=5
相除求商时可以直接约去公因数5有9/4=2...1
则商为2，但是求余数时要乘上当时约去的公因数5，即余数等于5
可以余数一定是公因数的倍数
故不可能存在比余数大的公因数
```
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if str1+str2!=str2+str1:
            return ''
        def dev(a,b):
            c=a%b
            if c==0:return b
            else: return dev(b,c)
        a=len(str1)
        b=len(str2)
        if a<b:
            a,b=b,a
        return str2[:dev(a,b)]
```


