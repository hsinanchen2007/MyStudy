### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int cuttingRope(int n) {
        if(n == 2)
            return 1;
        if(n == 3)
            return 2;
        int product = 1;
        while(n>4)
        {
            product*=3;
            n-=3;
        }
        product*=n;
        return product;
    }
};
```