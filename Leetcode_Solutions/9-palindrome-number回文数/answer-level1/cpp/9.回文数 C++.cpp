### 解题思路
1.思路与7题中的整数反转基本一致。
2.当传入数值小于0时返回false，当传入数值等于0时返回true。
3.当传入数值大于0时，反转后与原先数值进行比较，不同则返回false，相同则返回true。
### 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        int rev = 0;
        int pop = 0;
        int temp = x;
        if(x < 0){
            return false;
        }
        else if (x == 0){
            return true;
        }
        else if(x > 0){
            while(x != 0){
                pop = x % 10;
                x /= 10;
                if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return false;
                if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return false;
                rev = rev * 10 + pop;
            }
            if(temp == rev){
                return true;
            }
            else if(temp != rev){
                return false;
            }
        }
        return false;
    }
};
```