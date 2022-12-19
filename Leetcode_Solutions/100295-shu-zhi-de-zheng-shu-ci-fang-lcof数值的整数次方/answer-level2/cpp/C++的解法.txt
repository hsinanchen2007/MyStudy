### 解题思路
参考了大佬的解题思路，尤其要注意n转为-n时有越界的可能，注意用long来存储，因为我们可以保证最终结果不会越界即可。

### 代码

```cpp
class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0) return 0;
        long temp = n;
        double result = 1;
        if(temp < 0){
            x = 1/x;
            temp = -temp;
        }
        while(temp){
            if(temp&1 == 1){
                result = result * x;
                x *= x;
                temp>>=1;
            }else{
                x *= x;
                temp>>=1;
            }
        }
        return result;
    }
};
```