### 解题思路
替换
### 代码

```cpp
class Solution {
public:
    string replaceSpace(string s) {
       if(s.empty()) return s;
       string ans;
       for(auto e:s)
       {
           if(e==' ') ans+="%20";
           else ans+=e;
       }
       return ans;
    }
};
```