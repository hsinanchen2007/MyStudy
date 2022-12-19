```c++
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> codes{".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        unordered_set<string> s;
        for (auto& word : words) {
            string e;
            for (auto c : word) {
                e += codes[c - 'a'];
            }
            s.insert(e);
        }
        return s.size();
    }
};
```