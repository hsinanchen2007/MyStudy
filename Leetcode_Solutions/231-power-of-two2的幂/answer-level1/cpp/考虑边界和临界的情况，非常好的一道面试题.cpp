### 解题思路
注意n为1、2、3的情况，还有为负数的过程

### 代码

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
        bool res = false;
        while (n > 0)
        {
            if (n == 1)
            {
                res = true;
                break;
            }

            if (n  != n / 2 * 2)
            {
                break; 
            }


            n /= 2;
        }

        return res;
    }
};
```