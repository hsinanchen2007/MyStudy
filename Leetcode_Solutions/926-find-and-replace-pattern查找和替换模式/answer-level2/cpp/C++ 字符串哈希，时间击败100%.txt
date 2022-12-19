```
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int len=words.size();
        int Map1[129];
        int Map2[129];
        int _len=pattern.size();
        vector<string> res;
        for(int i=0;i<len;i++) {
            memset(Map1,-1, sizeof(Map1));
            memset(Map2,-1, sizeof(Map2));
            bool flag=true;
            for(int j=0;j<_len;j++) {
                if(Map1[words[i][j]-'a'+65]!=-1&&Map1[words[i][j]-'a'+65]!=(pattern[j]-'a'+65)) {
                    flag=false;
                    break;
                }
                if(Map2[pattern[j]-'a'+65]!=-1&&Map2[pattern[j]-'a'+65]!=words[i][j]-'a'+65) {
                    flag=false;
                    break;
                }
                Map1[words[i][j]-'a'+65]=pattern[j]-'a'+65;
                Map2[pattern[j]-'a'+65]=words[i][j]-'a'+65;
            }
            if(flag) {
                res.push_back(words[i]);
            }
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/4e06000e121e215e7ea43ebdf0d0809ca4e5c6e6452cacf6eb4906982a9991be-image.png)

