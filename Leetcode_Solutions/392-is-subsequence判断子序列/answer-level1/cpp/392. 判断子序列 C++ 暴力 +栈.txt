### 解题思路
暴力 + 栈

### 代码

```cpp
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.empty() && t.empty()){
            return true;
        }

        deque<char> buff;
        for(auto c:s){
            buff.push_back(c);
        }

        for (auto c:t){
            if(c == buff.front()){
                buff.pop_front();
            }

            if(buff.empty()){
                return true;
            }
        }

        return false;
    }
};
```