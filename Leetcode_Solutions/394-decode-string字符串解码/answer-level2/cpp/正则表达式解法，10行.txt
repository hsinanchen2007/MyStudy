一看到字符串的题，我就默默的掏出正则表达式。
```
class Solution {
public:
    inline string MultiStr(string &&sub, int num) {
        string rslt;
        for (int i = 0; i < num; ++i) {
            rslt.append(sub);
        }
        return rslt;
    }
    
    string decodeString(string s) {
        regex re(R"((\d+)\[(\w+)\])");
        smatch sm;
        while (regex_search(s, sm, re)) {
            s.replace(sm[0].first, sm[0].second, MultiStr(sm[2], stoi(sm[1])));
        }       
        return s;
    }
};
```
