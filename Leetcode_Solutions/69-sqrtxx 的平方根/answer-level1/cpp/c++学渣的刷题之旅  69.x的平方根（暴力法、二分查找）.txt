### 解题思路
暴力法直接从0开始循环，找到 ≥x 的为止
二分查找需要确认查找范围，由数学定理知当x>2时，其平方根属于(0,x/2)区间，则相应的二分查找的范围就确定了

### 代码
暴力法
```cpp
class Solution {
public:
    int mySqrt(int x) {
        int i=0;
        while(i*i<x){
            i++;
        }
        if(i*i==x)
            return i;
        return i-1;
    }
};
```

二分查找
```cpp
class Solution {
public:
    int mySqrt(int x) {
        if(x==0||x==1)
            return x;
        int left=0,right=x/2;
        while(left<=right){
            double mid=(left+right)/2;
            if(mid*mid==x)
                return mid;
            else if(mid*mid>x)
                right=mid-1;
            else
                left=mid+1;
        }
        return left-1;
    }
};
```