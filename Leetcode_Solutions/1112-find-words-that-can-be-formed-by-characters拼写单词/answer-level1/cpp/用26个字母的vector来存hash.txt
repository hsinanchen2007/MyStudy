
简单题
```
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> vt(26,0);
        vector<int> vt2(26,0);
        for(int i=0;i<chars.length();i++){
            vt2[chars[i] - 'a']++;
        }
        int ans = 0;
        for(int i=0;i<words.size();i++){
            int j = 0;
            for(int j=0;j<26;j++) vt[j] = vt2[j];
            for(;j<words[i].length();j++){
                if(!vt[words[i][j]-'a']){
                    break;
                }else{
                    vt[words[i][j] - 'a']--;
                }
            }
            if(j == words[i].length()){
                ans += words[i].length();
            }
        }
        return ans;
    }
};
```
