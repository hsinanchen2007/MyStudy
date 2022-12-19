### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> v(128,0);
        for(int i=0;i<s.length();i++){
            v[s[i]]++;
        }
        int t=0;
        for(int i=0;i<128;i++){
            if(v[i]%2){
                t++;
            }
        }
        if(t<2)return true;
        return false;
    }
};
```