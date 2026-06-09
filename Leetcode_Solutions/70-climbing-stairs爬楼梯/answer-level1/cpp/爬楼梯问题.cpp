### 解题思路
此处撰写解题思路
从基本情况考虑，n=1时只有一种方法，n=2时有两种方法，n=3时，就是在n=1时加上n=2的方法或者在n=2时加上n=1的方法，也就是当爬到n>3阶楼梯，必须先到n-1阶或n-2阶，此时方法总数就是这两种所包括的方法之和。
### 代码

```cpp
class Solution {
public:
    int climbStairs(int n) {
      

        if(n<=2){
            return n;
        }
        else{
            int a=1;
            int b=2;
            int c=0; 
            for(int i=2;i<n;i++){
              c=a+b;
              a=b;
              b=c;
          } 
          return c; 
        }
        

    }
};
```