### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int reverse(int x) { 

        if(-1*x > INT_MAX || -1*x < INT_MIN) return 0;

        int is_less_0 = 0;
        if(x < 0 ) {
            is_less_0 = 1;
            x = -1*x;
        }

        long int step = 10;
        while (x % step != x) step *= 10;

        long int jinzhi = step / 10;

        step = 10;
        long int res = 0;
        long int yu_val = 0;
        long int ge_val = 0;
        while( x % step != x){
            yu_val = x % step;
            ge_val = yu_val / (step / 10);

            res += ge_val*jinzhi;

            jinzhi /= 10;
            step *= 10;
        }
        yu_val = x % step;
        ge_val = yu_val / (step / 10);
        res += ge_val*jinzhi;

        if (is_less_0 == 1) res = -1*res;

        // int INT_MAX = 2147483647;
        // int INT_MIN = -2147483648;
        
        if(res > INT_MAX || res < INT_MIN) return 0;

        return res;

    }
};
```