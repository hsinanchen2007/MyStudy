### 解题思路


### 代码

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        int L = 0;
        int R = s.size() - 1;
        while(L < R)
        {
            char a = s[L];
            s[L] = s[R];
            s[R] = a;
            L++;
            R--;
        }
        return;
    }
};
```