### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    double myPow(double x, int n) {
    double sum=1;
    if(x==0) return 0;
    if(x==1) return 1;
    if(n==0) return 1; 
    if(n<0) {x=1/x; n=-(n+1);sum=x;}
    while(n != 0){
        if(n & 1 == 1){
            sum *= x;
        }
        x *= x;
        n = n >> 1;
    }
    return sum;
}  
};
```