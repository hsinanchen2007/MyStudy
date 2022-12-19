### 解题思路
此处撰写解题思路
就是long类型肯定是可以包含int类型的，毕竟long的类型有64位，而int类型只有32位。首先判断x是不是正数，如果是负数直接返回false。如果是正数就求x的逆序数，然后判断两个是否相等。相等就是回文数，否则就不是回文数。
### 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        int sway = x;
        if(x < 0)
            return false;
        long y=0;
        while(x){
            y = y*10 + x%10;
            x = x/10; 
        }
        if(sway == y)
            return true;
        else
            return false;
    }
};
```