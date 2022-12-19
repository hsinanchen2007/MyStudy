### 解题思路
理解二进制表达式

### 代码

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int cnt=0;
        while(n>0){
            cnt+=(n&1);
            n=n>>1;
        }
        return cnt==1;
    }
};
```