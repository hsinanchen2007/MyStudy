### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        int st = 0;
        while(st < s.size()){
            int right = st;
            while(right < s.size() && s[right] != ' ') right++;
            for(int i = 0; i < (right-st)/2; i++){
                char t = s[st+i];
                s[st+i] = s[right-i-1];
                s[right-i-1] = t;
            }
            st = right+1;
        }
        return s;
    }
};
```