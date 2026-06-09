```cpp
class Solution {
public:
        vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if(s.empty() || words.empty()) return ans;

        int wordlen = words[0].size();
        int vlen = words.size();

        if(s.size() < wordlen * vlen) return ans;

        sort(words.begin(),words.end());
        string ss;

        for(auto it : words) {
            ss.append(it);
        }

        for(int i = 0 ; i <= s.size() - wordlen * vlen ; i++) {
            vector<string> temp;
            for(int j = i ; j < i + wordlen * vlen ; j += wordlen) {
                temp.push_back(s.substr(j , wordlen));
            }
            sort(temp.begin() , temp.end());
            string sss;
            for(auto it : temp) {
                sss.append(it);
            }
            if(ss == sss) ans.push_back(i);
        }
        return ans;
    }
};
```