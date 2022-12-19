### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int cuttingRope(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2;
       long long int sum = 1;
        while(n > 4){
            sum *= 3;
            sum = sum % 1000000007;
            n -= 3;
        }
        return (sum * n) % 1000000007;

    }
};
```