### 解题思路
注意设为len-1，而不是len，因为i+1
 for (int i = 0;i < len-1;++i){
            if (mp[s[i]] < mp[s[i+1]])

### 代码

```cpp
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        
        int pos = 0;
        int len=s.size();
        for (int i = 0;i < len-1;++i){
            if (mp[s[i]] < mp[s[i+1]])
                pos -= mp[s[i]];
            else
                pos += mp[s[i]];
        }
        pos += mp[s[len-1]];
        
        return pos;

           
    }

};

```