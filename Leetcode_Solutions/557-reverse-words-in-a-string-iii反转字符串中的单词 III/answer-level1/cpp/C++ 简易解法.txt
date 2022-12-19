```
class Solution {
public:
    string reverseWords(string s) {
        s.append(" ");
        for(int i = 0, begin = 0, end = 0; i < s.length(); i++) {
            if(s[i] == ' ') {
                end = i - 1;
                while(begin < end)
                    swap(s[begin++], s[end--]);
                begin = i + 1;
            }
        }
        s.pop_back();
        return s;
    }
};
```
