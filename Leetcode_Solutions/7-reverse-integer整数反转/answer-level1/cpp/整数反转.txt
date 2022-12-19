### 解题思路
初始化结果res为0，while循环，如果商不为0，则res = res * 10 + x % 10，最后判断是否溢出

### 代码

```cpp
class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        
        while(abs(x) != 0){
            
            res = res * 10 + x % 10;
            x = x / 10;
        }
        if(res > (pow(2,31)-1) || res < -(pow(2,31)))return 0;
        return res;    
    }
};
```