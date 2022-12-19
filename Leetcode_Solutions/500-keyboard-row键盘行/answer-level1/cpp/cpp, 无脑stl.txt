```
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> results; 
        for (auto&& word : words) {
            int count = 0;
            if (word.find_first_of("QWERTYUIOPqwertyuiop") != std::string::npos) {
                ++count;
            }
            if (word.find_first_of("ASDFGHJKLasdfghjkl") != std::string::npos) {
                ++count;
            }
            if (count == 0 || (count == 1 &&
                word.find_first_of("ZXCVBNMzxcvbnm") == std::string::npos)) {
                results.emplace_back(std::move(word));
            }
        }
        return results;
    }
};
```
