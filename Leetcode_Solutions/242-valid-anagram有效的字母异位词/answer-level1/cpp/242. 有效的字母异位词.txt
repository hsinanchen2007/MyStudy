具体[见此](https://newdee.gitbook.io/leetcode/leetcode-index/242.valid_anagram)  

```
class Solution {
public:
    bool isAnagram(string s, string t) {
       int s1[26]={0};
        int t1[26]={0};
        for(auto c:s)
            s1[c-'a']++;
        
        for(auto c:t)
            t1[c-'a']++;
        for(int i=0;i<26;i++)
            if(s1[i]!=t1[i]) return false;
        return true;
    }
};
```

> 执行用时 : 12 ms, 在Valid Anagram的C++提交中击败了97.08% 的用户  
内存消耗 : 9.5 MB, 在Valid Anagram的C++提交中击败了8.77% 的用户