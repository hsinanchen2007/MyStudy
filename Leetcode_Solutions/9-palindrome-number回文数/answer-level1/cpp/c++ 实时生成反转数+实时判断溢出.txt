### 解题思路
用的还是老一套trick，先上转再回转。

这都能96% 100%？？？

不算作弊吧？

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int t = x;
        long r = 0;
        while(t > 0){
            r = r * 10 + t % 10;
            t /= 10;
            if(r > INT_MAX) return false;
        }
        return r == x;
    }
};
```