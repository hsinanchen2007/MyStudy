来回两次之后，数组长度为原来的1/4向下取整，首项和末项根据数组长度mod4余数会有稍微的变化。

针对mod4余数穷举讨论不难得到递推关系，见代码。

最后如果剩的不足3项，返回的一定是最后一项，剩3项则是中间的项。

```
class Solution {
public:
    int lastRemaining(int n) {
        int begin=1,d=1,end=n;
        while(n>=4){
            if(n%4<2){
                begin+=d;
                end-=(2+n%4)*d;
            }else{
                begin+=3*d;
                end-=(n%4)*d;
            }
            d=d*4;
            n>>=2;
        }
        return end-d*(n==3);
    }
};
```
