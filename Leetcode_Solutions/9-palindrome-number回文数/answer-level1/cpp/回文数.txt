### 解题思路
此处撰写解题思路
双指针解法
### 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int a[20] = {0};
        int i = 0;
        while(x)
        {
            a[i++] = x % 10;
            x /= 10;
        }
        int L = 0;
        int R = i - 1;
        while(L<R)
        {
            if(a[L] != a[R])
            {
                return false;
            }
            else
            {
                L++;
                R--;
            }
        }
        return true;
    }
};
```