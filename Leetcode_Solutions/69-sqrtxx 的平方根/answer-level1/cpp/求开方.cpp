
二分法
----------
```cpp
class Solution {
public:
    //sqrt一定在0~x之间，使用二分法找到满足sqrt=x/sqrt的值
    //一般二分法
    int mySqrt(int x) {
        if(x==1)return x;
        int low=1,high=x;

        //结束循环时，high会<low
        while(low<=high){
            int mid=low+(high-low)/2;
            //避免使用mid*mid，可能会溢出
            int sqrt=x/mid;
            if(mid==sqrt){
                return mid;
            //mid偏大了，移动high指针到mid前
            }else if(mid>sqrt){
                high=mid-1;
            //mid偏小了，移动low指针到mid后
            }else{
                low=mid+1;
            }
        }
        //因为返回整数部分，所以此处返回小的
        return high;
    }
};
```