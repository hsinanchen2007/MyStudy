```cpp
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> hash;
        unordered_map<string, bool> isMapped;
        size_t cur = 0, startPos = 0;
        size_t foundBlank = str.find_first_of(" ", 0);
        string nowSub;
        while (foundBlank != string::npos) {
            if (cur == pattern.length()) return false;
            nowSub = str.substr(startPos, foundBlank - startPos);
            if (hash.find(pattern[cur]) != hash.end()) {
                if (hash[pattern[cur]] != nowSub) return false;
            } else {
                if (isMapped.find(nowSub) != isMapped.end()) return false;
                hash[pattern[cur]] = nowSub;
                isMapped[nowSub] = true;
            }
            cur++;
            startPos = foundBlank + 1;
            foundBlank = str.find_first_of(" ", startPos);
        }
        nowSub = str.substr(startPos);
        if (hash.find(pattern[cur]) != hash.end()) {
            if (hash[pattern[cur]] != nowSub) return false;
        } else {
            if (isMapped.find(nowSub) != isMapped.end()) return false;
            hash[pattern[cur]] = nowSub;
            isMapped[nowSub] = true;
        }
        cur++;
        if (cur == pattern.length()) return true;
        else return false;
    }
};
```