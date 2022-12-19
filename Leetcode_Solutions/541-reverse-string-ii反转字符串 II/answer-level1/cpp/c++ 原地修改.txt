### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string reverseStr(string s, int k) {
        int st = 0;
        while(st < s.size()){
            int length = min(k, (int)s.size()-st);
            for(int i = 0; i < length/2; i++){
                int t = s[st+i];
                s[st+i] = s[st+length-1-i];
                s[st+length-i-1] = t;
            }
            st = st+2*k;
        }
        return s;
    }
};
```