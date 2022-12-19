```
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        for(char c:t) m[c]++;
        int left = 0, cnt = 0, wid = INT_MAX;
        string res = "";
        for(int i=0; i<s.size(); i++)  {
            if(m[s[i]]-- > 0) cnt++;
            while(cnt == t.size()) {
                if(wid > i - left + 1) {
                    wid = i - left + 1;
                    res = s.substr(left, wid);
                }
                if(++m[s[left]] > 0) cnt--;
                left++;
            }
        }
        return res;
    }
};
```
