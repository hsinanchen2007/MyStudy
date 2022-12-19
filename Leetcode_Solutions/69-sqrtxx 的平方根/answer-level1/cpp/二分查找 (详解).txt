思路比较清晰，利用二分查找比较快
为了解决int可能的溢出，我将乘积转化为除商的比较
同时需要注意以下几点：
1、0不能做除数，否则会报错,所以x<=1直接返回 
2、如果i>j时跳出循环，说明当i==j时mid<x/mid成立，二分结束，此时右边界即为开方 
```
class Solution {
public:
    int mySqrt(int x) {
    if(x<=1) return x;
   	int i=1,j=x/2,mid=0;
    while(i<=j)
    {
        mid=i+(j-i)/2;
        if(mid==x/mid) return mid;
        if(mid<x/mid)  i=mid+1;
        else  j=mid-1;
    }
    return j;
    }
};

```
有问题欢迎大家指正。