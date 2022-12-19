# 思路
1. 遍历所有情况1 * 1 ， 2 * 2...
2. 直到y * y > x 时候再返回 y - 1


```
class Solution {
public:
    int middle(int x , long y = 0){
        if(y * y > x){
            return y - 1;
        }
        return middle(x , ++y);
    }
    int mySqrt(int x) {
        return middle(x);
    }
};
```
