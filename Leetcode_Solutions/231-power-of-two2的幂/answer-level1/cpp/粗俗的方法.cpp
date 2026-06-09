### 解题思路
n>0且n的二进制只有一位为1

### 代码

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<0)return false;
        int count = 0;
        while(n)
        {
            if(n&1)
            {
                count++;
            }
            n>>=1;
        }
        if(count == 1) return true;
        else return false;
    }
};
```