先了解一下牛顿迭代公式是啥意思？它用来求 $f(x)=0$ 的解，说白了就是求 $f(x)$ 这个函数的零点。

具体推导迭代公式的过程 [看这](https://baike.baidu.com/item/%E7%89%9B%E9%A1%BF%E8%BF%AD%E4%BB%A3%E6%B3%95/10887580?fr=aladdin)。

现在给你一个x让求它的平方根 $r$，即 $r*r=x$，进一步写为 $x-r*r=0$，改写成函数就是相当于求 $f(x)=x-r*r$ 的零点，然后就套用牛顿迭代公式


```C++ []
class Solution {
public:
    int mySqrt(int x) {
        if(x==0)
            return x;
        double r=1;//迭代初始值
        while(fabs(r*r-x)>0.5)//精度小于0.5就停止迭代
        {
            r=(r+x/r)/2;
        }
        return int(r);
    }
};
```