```
class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
            //他的推理过程应该是这样的
            //对于第一个乘客，它要么选对位置了1/n，这样大家都是对的,n乘客也是对的
            //第一个乘客选了最后一个位置1/n*0，这样肯定最后一个乘客坐不对
            //第一个人选了2~k~n-1的位置，那么其对应的问题就变成了对k求和1/n*f(n-k+1);
            //综上，递推关系应该f(n)=1/n+1/n*f(n-1)+1/n*f(n-2)+...+1/n*f(2)
            //再用f(n-1)也用这个方法表示，就可以得到下面那个f(n)和f(n-1)的递推关系
            //也即f(n)=1/n+(n-2)/n*f(n-1);
            if (n==1) return 1.0;
            return 1.0/n+(n-2.0)/n*nthPersonGetsNthSeat(n-1);
    }
};
```
