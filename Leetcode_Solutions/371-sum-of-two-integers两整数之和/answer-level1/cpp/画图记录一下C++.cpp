### 解题思路
![371.png](https://pic.leetcode-cn.com/bc2e6a4d99ad1be22e60bc71ce81dcbb13ba2462438ac04bca5248c94f48e41f-371.png)


### 代码

```cpp
class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0){
            int sum   = a ^ b;
            int carry = ((unsigned int)(a & b) << 1);
            a = sum;
            b = carry;
        }
        return a; 
    }
};
```