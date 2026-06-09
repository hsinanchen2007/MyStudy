把单词编码为摩尔斯密码，用哈希表去重。
```
class Solution {
public:
    int uniqueMorseRepresentations(const vector<string>& words) {
        unordered_set<string> s;
        for (const auto& word : words) {
            ostringstream os;
            for (const auto& ch : word)
                os << dict[tolower(ch) - 'a'];
            s.insert(os.str());
        }
        return s.size();
    }
private:
    const vector<string> dict{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
};
```
