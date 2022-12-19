```
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int>hash;
        for(int i=0;i<magazine.length();++i){
            if(hash.find(magazine[i])==hash.end()) hash[magazine[i]]=1;
            else hash[magazine[i]]++;
        }
        for(int i=0;i<ransomNote.length();++i){
            if(hash.find(ransomNote[i])==hash.end()||hash[ransomNote[i]]==0) return false;
            else hash[ransomNote[i]]--;
        }
        return true;
    }
};
```
