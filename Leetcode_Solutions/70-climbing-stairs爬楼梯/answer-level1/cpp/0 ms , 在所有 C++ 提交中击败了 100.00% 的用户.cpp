### 解题思路
果然还是这种类似dp table的执行效率高。

### 代码

```cpp
class Solution {
public:
    long climbStairs(int n) {
        if(n==1||n==2||n==3){
            return n;
        }
        long a = 1;
        long b = 2;
        int i = 0;
        while(i<(n-1)/2){
            a = a + b;
            b = a + b;
            i++;
        }
        if(n&1) return a;
        else return b;
    }
};
```