1. 按照单词中字母首次出现的顺序，把字母映射到一个递增序列，比如
["abc", "deq", "mee", "aqq", "dkd", "ccc"]被映射为
["ABC", "ABC", "ABB", "ABB", "ABA", "AAA"]
而pattern "abb" 也被映射为 "ABB"
2. 之后在单词列表中进行字符串匹配。

```
class Solution {
public:
    vector<string> findAndReplacePattern(const vector<string>& words, const string& pattern) {
        vector<string> ans;
        string symbol_pattern = convert(pattern);
        for (const auto& word : words)
            if (symbol_pattern == convert(word))
                ans.push_back(word);
        return ans;
    }

private:
    string convert(const string& s) {
        ostringstream os;
        unordered_map<char, char> order;
        char index = 'A';
        for (const auto& ch : s) {
            if (!order.count(ch)) order[ch] = index++;
            os << order[ch];
        }
        return os.str();
    }
};
```
