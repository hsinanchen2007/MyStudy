### 解题思路
1.使用模运算即模10去除整数个位，pop即为每次取x值的个位，每次取个位数后就将原值除10，并将个位数增加至rev返回值中。
2.注意到int的最大值为即INT_MAX = 214748364，int最小值为即INT_MIN = -2147483648，返回值必须在最小值与最大值之间。

### 代码

```cpp
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0){
            int pop = x % 10; 
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};
```