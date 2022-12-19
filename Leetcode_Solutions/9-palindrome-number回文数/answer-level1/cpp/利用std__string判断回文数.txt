### 解题思路
1.利用C++11中的std::string的特性进行判断，只需要判断string的正序和倒序是否一致即可

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        std::string s = std::to_string(x);

        std::string cs = "";
        cs.append(s.rbegin(), s.rend());

        return (cs == s)?true:false;
    }
};
```