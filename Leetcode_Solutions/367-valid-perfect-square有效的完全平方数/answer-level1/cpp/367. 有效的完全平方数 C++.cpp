### 解题思路
1.使用牛顿迭代法求完全平方数。

### 代码

```cpp
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num < 2) return true;
        
        long x = num / 2;
        while(x * x > num){
            x = (x + num / x) / 2;
        }
        return (x * x == num);
    }
};
```