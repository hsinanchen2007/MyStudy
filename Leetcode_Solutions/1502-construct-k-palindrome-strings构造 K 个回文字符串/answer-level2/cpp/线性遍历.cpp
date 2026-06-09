### 解题思路
通计每个字母出现的次数，出现奇数次的字母不能超过k;
### 代码

```cpp
class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> alghCount(26,0);
        if(k>s.length())
        return false;
        for(int i=0;i<s.length();i++)
        {
            alghCount[s[i]-'a']++;
        }
        int oddCount=0;
        for(int i=0;i<26;i++)
        {
            if(alghCount[i]%2)
            oddCount++;
        }
        if(oddCount>k)
        return false;
        return true;
    }
};
```