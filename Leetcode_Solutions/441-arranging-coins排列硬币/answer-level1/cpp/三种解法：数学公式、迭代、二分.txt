### 解题思路
数学公式我是真的不会推，看了下别人得代码：由n=x*(x+1)/2得x=(-1+sqrt(8*n+1))/2;

### 代码
数学公式
```cpp
class Solution {
public:
    int arrangeCoins(int n) {
        return (-1+sqrt((long)n*8+1))/2;
    }
};
```
二分
```
class Solution {
public:
    int arrangeCoins(int n) {
        int l=0,r=n;
        while(l<r){
            int mid=(l+r)>>1;
            if(sumof(mid)>n) r=mid;
            else l=mid+1;
        }
        return sumof(l)==n?(int)l:(int)l-1;
    }
    long sumof(int n){
        return (long)n*(n+1)/2;
    }
};
```
迭代
```
class Solution {
public:
    int arrangeCoins(int n) {
        long res=0,sum=0,temp=1;
        while(sum<n){
            sum+=temp;
            temp++;
            res++;
        }
        return sum==n?(int)res:(int)res-1;
    }
};
```

