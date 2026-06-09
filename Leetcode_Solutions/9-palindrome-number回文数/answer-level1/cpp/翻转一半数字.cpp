### 解题思路
翻转一半的字符

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if (x == 0) return true;
        if(x < 0 || x % 10 == 0) return false;
        int revertedNumber = 0;
        while(x > revertedNumber){
            revertedNumber= revertedNumber * 10 + x % 10;
            x /= 10;
        }
        return x==revertedNumber || revertedNumber / 10 == x;
    }
};
```