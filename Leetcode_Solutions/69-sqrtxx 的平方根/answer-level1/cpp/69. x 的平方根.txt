## 牛顿迭代法
**牛顿迭代法用来求单调函数零点的近似值**
![牛顿迭代法.png](https://pic.leetcode-cn.com/79c736088e5633991c8517a5504c408dea54812a57f3c9a603b13d5c9a6ce25d-%E7%89%9B%E9%A1%BF%E8%BF%AD%E4%BB%A3%E6%B3%95.png)
*图是我偷来的，侵删*
```
class Solution {
public:
    int mySqrt(int y0) {
        long long x = y0;
        while(x*x > y0){
            x = (x + y0/x)/2; //因为有近似，可能会出错
        }
        return (int)x;
    }
};
```


## 二分法
```
class Solution {
public:
    int mySqrt(int x) {
        if(x<2) return x;
        int left=1, right=x, mid;
        long long pow; //用long long型的pow来暂存平方值
        while(left < right){
            mid = (right - left) / 2 + left;
            pow = (long long)mid * mid;
            if(pow > x)
                right = mid;
            else
                left = mid+1;
        }
        //left是大于目标值的第一个整数
        return left - 1;
    }
};
```

## 暴力法
```
class Solution {
public:
    int mySqrt(int x) {
        int i;
        for(i=1; i<=(long long)x+1; i++){
            long long ii = (long long)i*i;
            if(ii>x) break;
        }
        return i-1;
    }
};
```