```
class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> count_b(26,0);
        for(string s:B) {
            int count[26];
            memset(count, 0, sizeof(count));
            for(char c:s) {
                count[c-'a']++;
            }
            for(int i=0;i<26;i++) {
                if(count[i]>count_b[i]) {
                    count_b[i]=count[i];
                }
            }
        }
        vector<string> res;
        for(string s:A) {
            int count[26];
            memset(count, 0, sizeof(count));
            for(char c:s) {
                count[c-'a']++;
            }
            bool flag=true;
            for(int i=0;i<26;i++) {
                if(count[i]<count_b[i]) {
                    flag=false;
                    break;
                }
            }
            if(flag) {
                res.push_back(s);
            }
        }
        return res;
    }
};
```
