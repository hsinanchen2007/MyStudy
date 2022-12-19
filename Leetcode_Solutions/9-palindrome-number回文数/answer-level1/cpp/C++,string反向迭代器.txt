### 解题思路
先将int类型转换成string 再利用反向迭代器判断

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        string s=to_string(x);
        if(s==string(s.rbegin(),s.rend())) return true;
        return false;
    }
};
```