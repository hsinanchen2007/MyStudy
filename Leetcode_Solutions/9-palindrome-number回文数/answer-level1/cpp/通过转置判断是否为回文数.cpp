### 解题思路
如果该数小于0，那么肯定不是回文数；如果非负，那么先将该数进行转置，将转置后的数减去原数，如果结果为0，则为true，否则为false

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        int tmp = x;
        long long res = 0;
        while(abs(x) != 0){
            
            res = res * 10 + x % 10;
            x = x / 10;
        }
        if (tmp-res == 0) return true;
        return false;
    }
};
```