该方法通过近似值导函数逼近找到f(x) = 0的近似解
难点应该在于找到该f(x)

题目是已知 x、n， 求x的n次方，一定不要把x当作未知数，因为x在计算过程中是已知的。

设k=x^n, 那么`ln(k)/ln(x) = n` 求k就是找到`f(k)=1/ln(x)*ln(k)-n`与x轴的交点

找到了函数，就可以通过设初值ki，获得f(ki)，在(ki,f(ki)找到导函数 `y=f'(ki)x+f(ki)-f'(ki)*ki`
y = 0时，解得`ki+1=ki-f(ki)/f'(ki)`。然后通过循环当ki与ki+1足够近时，认为ki就是f(k)的解。
`ki+1=ki-f(ki)/f'(ki)`该方程是通解，只要找到合适的f(k)就可以直接代入进去求解。

思路理清之后，将`f(k)=1/log(x)*log(k)-n`和导函数`f'(k)=1/log(x)*(1/k)`代入可以解得`k=(n*log(x)-log(k)+1)*k`。但是由于对数的限制，k必须大于零才能继续迭代，所以该公式只能解决n>0且x>1的情况。通过观察对数函数图像可知，如果x<-1,可以简单进行取反然后判断n是否为奇数；如果n<0我们可以使用-n，此时结果是k的倒数；如果-1<x<1, 同样是k的倒数。
综上最终代码如下。
```
import math
class Solution:
    def myPow(self, x: float, n: int) -> float:
        if x == 0 or x == 1:
            return x
        if n == 0:
            return 1
        if x == -1:
            return -1 if n%2==1 else 1

        #一定要为正才能继续运算
        temp = x
        if x < 0:
            temp = -x
        temp = abs(math.log(temp)*n)
        
        def getRes(x, n ,k):
            if x < 1 and x > -1:
                k = 1/k
            if n < 0:
                k = 1/k
            return k

        k0 = 0
        k = 1
        while abs(k0-k) >= 0.00001:
            k0 = k
            k = (temp + 1 - math.log(k)) * k
            res = getRes(x, n ,k)
            # 案例中有个小数的N次方
            if abs(res)<0.000001:
                return 0

        if x < 0 and n%2==1:
            res = -res

        return res
```
写完后由于用例中有小数的很大数次方，所以添加了是否是很小数的判断，近似返回零。