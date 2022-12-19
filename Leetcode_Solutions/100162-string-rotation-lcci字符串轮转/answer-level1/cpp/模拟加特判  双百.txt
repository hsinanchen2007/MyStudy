### 解题思路
先判断两者是否相等和两者大小是否相等，再模拟旋转

### 代码

```cpp
class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if(s1.size()!=s2.size())
            return false;
        if(s1==s2)
            return true;
        for(int i=0;i<s1.size();i++)
        {
            s1.insert(s1.size(),s1.substr(0,1));
            s1.erase(0,1);
            if(s1==s2)
                return true;
        }
        return false;
    }
};
```