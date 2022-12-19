1. 使用模板可以写出类型无关代码。
2. pattern 和 str 遵循相同的规律，当且仅当可在 pattern 和 str 间建立双射。
3. 可以把 pattern 和 str 都映射到同一个序列，双射有自反，对称，传递性质，属于等价关系。
4. 把 pattern 转换为 vector<char> v_pattern，str 转换为 vector<string> v_str，然后可以对 v_pattern, v_str做完全相同的预处理。
5. 对 v_pattern 和 v_str 按照其中符号首次出现的顺序，把符号映射到递增序列。
6. 取递增序列，是为了序列中的符号唯一，不重复。
7. 递增序列可以取整数, 0, 1, 2, 3, ...。
8. 这里取ASCII码序列 "@ABCDEFG"...。
9. "abba" 被映射为 "@AA@"。
10. "dog cat cat fish" 被映射为 "@AAB"。
11. 然后检查映射的结果是否相同。

```
class Solution {
public:
    bool wordPattern(const string& pattern, const string& str) {
        vector<char> v_pattern(pattern.begin(), pattern.end());
        vector<string> v_str = split_by_space(str);
        return symbolize(v_pattern) == symbolize(v_str);
    }
    
private:
    template<typename T>
    vector<char> symbolize(const vector<T>& v) {
        char index = '@';
        unordered_map<T, char> dict;
        vector<char> ans;
        for (const auto& item : v) {
            if (!dict.count(item)) dict[item] = index++;
            ans.push_back(dict[item]);
        }
        return ans;
    }
    
    vector<string> split_by_space(const string& str) {
        vector<string> ans;
        istringstream is(str);
        string s;
        while (is >> s) ans.push_back(s);
        return ans;
    }
};
```
