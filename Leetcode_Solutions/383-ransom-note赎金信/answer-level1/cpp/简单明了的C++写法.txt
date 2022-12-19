```
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int target[26]={0};
        int source[26]={0};
        for(int i(0);i<ransomNote.size();i++)
        {
            target[ransomNote[i]-'a']++;
        }
        
        for(int i(0);i<magazine.size();i++)
        {
            source[magazine[i]-'a']++;
        }
        
        for(int i(0);i<26;i++)
        {
            if(target[i]>source[i])
                return false;
        }
        return true;
    }
};
```
简单明了
