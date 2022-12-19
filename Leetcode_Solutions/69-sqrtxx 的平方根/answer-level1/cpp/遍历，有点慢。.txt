### 解题思路
此处撰写解题思路
给变量long long型，防止溢出，任何一个数的平方根都小于等于它的二分之一加一。
记得在循环里面也给i一个longlong类型，要不然会溢出。
### 代码

```cpp
class Solution {
public:
    int mySqrt(int x) {
        long long num=x/2+1;
        for(long long i=0; i<=num; ++i){
            if((i*i<=x)&&((i+1)*(i+1)>x)){
                return i;
            }
        }
        return -1;
    }
};
```