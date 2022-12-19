### 解题思路
1. 一个数的平方根一定小于x/2+1；
2. 最重要的是寻找正确界限，如果来不及尝试就记住代码。

### 代码

```cpp
class Solution {
public:
    int mySqrt(int x) {
        int i = 0;
        int j = x/2+1;
        while(i<=j){
            long mid = (i+j)/2;
            if(mid * mid < x){
                i = mid +1;}
            else if(mid*mid >x){
                j = mid -1;
            }
            else 
                return mid;
        }
        return j;
    }
};
```