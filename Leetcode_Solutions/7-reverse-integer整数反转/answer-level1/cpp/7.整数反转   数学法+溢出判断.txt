### 解题思路
int pop=x%10;
            if (y > INT_MAX/10 || (y == INT_MAX / 10 && pop > 7)) return 0;
            if (y < INT_MIN/10 || (y == INT_MIN / 10 && pop < -8)) return 0;

### 代码

```cpp
class Solution {
public:
    int reverse(int x) {
        int flag=0;
        int y=0;
        while(x){
            int pop=x%10;
            if (y > INT_MAX/10 || (y == INT_MAX / 10 && pop > 7)) return 0;
            if (y < INT_MIN/10 || (y == INT_MIN / 10 && pop < -8)) return 0;
            y=y*10+x%10;
            x/=10;
        }
        return y;
    }
};
```