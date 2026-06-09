### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    
    int reverse(int x) {
        int r = 0;
        while(x){
            if(r>INT_MAX/10||r<INT_MIN/10) return 0;
            r = r*10 + x%10;
            x/=10;
        }
        return r;
   
    }
};
```