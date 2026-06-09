### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
    if ( x >= 0 && x <= 9 ) return true;
    if ( !x )   return false;
    string y = to_string(x);
    int a = y.length();
    string z = y;
    reverse(y.begin(),y.end());
    if ( y == z ) return true;
    else return false;
    }
};
```