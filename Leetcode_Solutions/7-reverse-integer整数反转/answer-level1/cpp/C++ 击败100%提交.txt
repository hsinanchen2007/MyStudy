### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int reverse(int x) {

        long int res = 0;
        while(x){
            
            res = res*10 + x%10;
            x /= 10;
            if(res > INT_MAX || res < INT_MIN) return 0;
        }        
        return res;
        
    }
};
```