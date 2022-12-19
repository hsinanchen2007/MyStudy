### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        char temp;
        if(s.size() > 1)
        for(int l = 0,r = s.size()-1;l < r;l++,r--){
            temp = s[l];
            s[l] = s[r];
            s[r] = temp;
        }
        
    }
};
```