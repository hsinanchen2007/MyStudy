### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int countSegments(string s) {
        bool lastSpace = true;
        int res = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i]!=' ' && lastSpace){
                res++;
                lastSpace = false;
            }
            if(s[i] == ' ')
                lastSpace = true;
        }
        return res;
    }
};
```