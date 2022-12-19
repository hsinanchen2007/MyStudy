```
class Solution:
    def mySqrt(self, x: int) -> int:
        x1, x2 = x, 0
        while x1-x2>0.5 or x2-x1>0.5:
            x2=x1
            x1=(x/x1+x1)/2          ##逼近过程
        return int(x1)
```
仅仅是不断用(x,f(x))的切线来逼近方程x^2-a=0的根。根号a实际上就是x^2-a=0的一个正实根，这个函数的导数是2x。也就是说，函数上任一点(x,f(x))处的切线斜率是2x。那么，x-f(x)/(2x)就是一个比x更接近的近似值。代入 f(x)=x^2-a得到x-(x^2-a)/(2x)，也就是(x+a/x)/2。