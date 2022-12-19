### 解题思路
n&(n-1)

### 代码

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1)
        {
            return true;
        }
        int result=0;
        if(n<0)
        {
            return false;
        }
        while(n)
        {
            n=n&(n-1);
            result++;
        }
        if(result==1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
```