### 解题思路

### 代码

```cpp
class Solution {
public:
int firstUniqChar(string s) {
    unordered_map<char, int> mp1;
    unordered_map<char, int> mp2;
    for(int i = 0 ; i < s.length() ; ++i)
    {
        mp1[s[i]]++;
        if(!mp2.count(s[i]))
            mp2[s[i]] = i;
    }
    for(int i = 0 ; i < s.length() ; ++i)
    {
        if(mp1[s[i]] == 1)
        {
            //cout<<it->first<<endl;
            return mp2[s[i]];
        }
    }
    return -1;
}
};
```