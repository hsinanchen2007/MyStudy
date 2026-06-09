### 解题思路
翻转数字

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if(x == 0)
        {
            return true;
        }
        long y = x;
        long c = 0;
        while(y > 0)
        {
            c= c*10+y%10;
            y /=10;
        }
        if(x == c)
        {
            return true;
        }
        else
            return false;     
    }
};
```