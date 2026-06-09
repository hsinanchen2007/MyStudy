### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string compressString(string S) {
        string compacted = "";
        if(S.size() <= 1) return S;
        int l = 0;
        int r = 1;
        while(r < S.size()){
            if(S[l] != S[r]){
                string len = to_string(r-l);
                compacted += (S[l] + len);
                l = r;
            }
            ++r;
        }

        string len = to_string(r-l);
        compacted += (S[l] + len);
      
        return S.size() <= compacted.size() ? S : compacted;
    }
};
```