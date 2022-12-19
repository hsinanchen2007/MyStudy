### 解题思路
使用流将int转换为string，反转string，判断是否是回文

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        stringstream s;
        s<<x;
        string s1;
        s>>s1;
        string s2=s1;
        std::reverse(s1.begin(),s1.end());
        if(s1==s2)
        return true;
        else
        return false;
    }
};
```