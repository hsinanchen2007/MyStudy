```
class Solution {
public:
    inline int uniqueMorseRepresentations(vector<string>& words) {
        set<string> results;
        for (const auto& word : words) {
            std::string result;
            for (auto ch : word) {
                result += codes[ch - 'a'];
            }
            results.emplace(result);
        }
        return static_cast<int>(results.size());
    }

private:
    array<string, 26> codes = {
        ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...",
        "-","..-","...-",".--","-..-","-.--","--.."
    };
};
```
