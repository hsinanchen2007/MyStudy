```
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> a(30,0);
        for(int i=0; i<magazine.length(); i++)
            a[int(magazine[i]-'a')]++;//统计magazine数组里面的字母
        for(int i=0; i<ransomNote.length(); i++)
            a[int(ransomNote[i]-'a')]--;//减去赎金需要用的字母
        for(int i=0; i<30; i++)
            if(a[i]<0) return false;//小于0代表不够用。
        return true;
    }
};
```
