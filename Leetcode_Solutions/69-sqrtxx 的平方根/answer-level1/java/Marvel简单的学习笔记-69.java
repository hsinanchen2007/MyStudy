### 解法一：牛顿迭代法
由本题启发，解方程或求解函数的题均可尝试使用牛顿迭代法。原理如下：
假设求解的函数为f(x)=0
其含义是求出函数曲线与x轴交点的横坐标值。
不妨假设这个值为t（可假设为任意值），显然t不是最终答案，我们要做的就是不断地更新假设的值，不断逼近直至得到最终答案。
则可以求出曲线f(x)在点(t,f(t))上的切线方程。
如何求？已知一点(t,f(t))，和一斜率k=f'(t)，一点一斜率可以得到唯一一条直线。
将其写成y=kx+b的形式，即y=f'(t)x+f(t)-f'(t)t
这是我们通过初始假设的值t得到的直线，我们下一个假设的答案就是这条直线和x轴的交点的横坐标。
故下一个t为t'=t-f(t)/f'(t)
这是第二个假设的值，同样用这个新的t又可以求出曲线f(x)在点(t,f(t))上的切线方程。
不断重复上述过程，最终得到的t就是答案。
代入到本题中，
f(x)=c-x*x，c是给定的值，x是待求的值，即常数c的根号
初始的t假设为c/2
通过递归，令新的t等于t-f(t)/f'(t)
本题，f(t)=c-t*t，f'(t)=-2t
t-f(t)/f'(t)=t-(c-t*t)/(-2t)=t/2+c/2t=(t+c/t)/2，c是给定的参数

### 代码

```java
class Solution {
    public int mySqrt(int x) {
        if(x==1 || x==0)    return x;
        int ans=x/2;
        while(ans>x/ans)
        {
            ans=(ans+x/ans)/2;
        }
        return ans;
    }
}
```
### 解法二：二分法
与之前的二分法题目类似，使用upper_bound()和lower_bound()方法的思路。当求解是否存在的问题时，可使用传统的二分法，当求解找出满足某个条件的值时，使用upper_bound()和lower_bound()方法。前者是找出序列中第一个大于某个值的数；后者是找出序列中第一个大于等于某个值的数。写法已有固定模板，此处不赘述，最后返回结果是lo，循环结束标志是lo==hi。本题其实相当于找出第一个大于mid/x的值，找出后将其减一就是最终答案。

### 代码

```java
class Solution {
    public int mySqrt(int x) {
        if(x==1 || x==0)    return x;
        int lo=1,hi=x/2+1;
        while(lo<hi)
        {
            int mid=lo+(hi-lo)/2;
            if(mid>mid/x)   hi=mid;
            else            lo=mid+1;
        }
        return lo-1;
    }
}
```