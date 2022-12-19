### 解题思路
纠结了半天，自己记录下取左右值的问题
还有溢出int的问题

### 代码

```cpp
class Solution {
public:
    int mySqrt(int x) {
        // long int i=0,a=0;
        // int flag = 1;
        // while(a<=x){
            
        //     if(a<x&&flag==1){
        //         if((a*a)>x){
        //             flag=0;
        //             continue;
        //         }
        //         i=a;
        //     }
        //     i++;
        //     a=i*i;
        // }
        // return i-1;

        //二分法左值
        // if(x==0) return 0;
        // int left = 1;
        // int right = x/2;
        // long mid,sqr;
        // while(left<right){
        //     mid = left + (right - left ) / 2; //mid =(left+right)/2;//二分的边界怎么搞
        //     if(mid< x/mid) {
        //         left = mid+1;
        //         if(left> x/left) return mid; //因为题目是向下取小，所以中值取左值的话，放大后，还需要一次判定，否侧就死循环了
        //     }
        //     else right = mid;  //等于也在这里处理
        // }
        // return left;

        //二分法右值
        if(x==0) return 0;
        int left = 1; //这里是1，不是0 ，才能保证在下面，求mid时不会溢出
        int right = x; //这里不用x/2 也不会溢出
        int mid,sqr;
        while(left<right){
            mid = left + (right - left +1) / 2;   //右值
            if(mid> x/mid) {           //这也可以保证不越界，而不是乘起来
                right = mid-1;
                //if(left> x/left) return mid; 
            }
            else left = mid;  
        }
        return left;
    }
};
```