### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int reverse(int x) {
        long sum = 0;
        while(x){
            sum = sum*10 + x%10;
            x /= 10;
        }
        if(sum > 2147483647 || sum < -2147483648) return 0;
        return sum;
    }
};
```