### 解题思路

规律；




### 代码

```cpp
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        if(n == 1) return 10;

        int i = 1;
        int x = 9;
        int ans = 10;

        while(i < 10 && i < n) {
            x = (10 - i) * x;
            ans += x;
            i++;
        }

         return ans;
    }
};
```