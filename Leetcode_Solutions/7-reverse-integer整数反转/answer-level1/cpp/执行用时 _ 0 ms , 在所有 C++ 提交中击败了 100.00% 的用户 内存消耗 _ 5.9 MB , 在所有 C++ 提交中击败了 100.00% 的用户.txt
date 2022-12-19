### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int reverse(int x) {
        bool isBigerThanZero = x >= 0 ? 1:0;
        
        int returnValue = 0;
        while(x)
        {
            if(returnValue > INT_MAX / 10 || returnValue < INT_MIN / 10) return 0;
            int value = x % 10;
            returnValue = returnValue * 10 + value;
            x = x / 10;
        }

        return returnValue;
    }
};
```