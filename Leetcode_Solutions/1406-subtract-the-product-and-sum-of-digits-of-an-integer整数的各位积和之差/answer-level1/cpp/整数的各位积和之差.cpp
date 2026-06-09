### 解题思路


### 代码

```cpp
class Solution {
public:
    int subtractProductAndSum(int n) {
        int mul = 1,sum = 0;
        while(n) mul *= n % 10,sum += n % 10,n /= 10;
        return mul - sum;
    }
};
```