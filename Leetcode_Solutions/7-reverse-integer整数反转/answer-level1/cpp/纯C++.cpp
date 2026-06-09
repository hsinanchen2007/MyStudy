### 解题思路
代码简短，快速实现

### 代码

```cpp
class Solution {
public:
    int reverse(int x) 
    {
        int max = 2147483647,min = -2147483648;
        int num = x;long res = 0;
        for( ;num != 0; num/= 10) res = res * 10 + num % 10;
        return ( res > max || res < min) ? 0 : res;
    }   
    
};
```