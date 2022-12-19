```
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<std::string> vec_str;
        split(str, ' ', vec_str);
        if (vec_str.size() != pattern.length()) {
            return false;
        }
        
        // str_map存储pattern字符串字符和对应的位置
        std::map<char, int> str_map;
        for (int index = 0; index < pattern.length(); ++index) {
            if (str_map.count(pattern[index]) > 0) {
                // 如果pattern字符串对应的index位置的字符和在str_map中搜寻到的字符串相同,
                // 则判断对应的位置的字符串和vec_str是否一样，不一样直接判断不匹配
                if (vec_str[index] != vec_str[str_map[pattern[index]]]) {
                    return false;
                }
            } else {
                // 将pattern字符和位置存入map
                str_map[pattern[index]] = index;
            }
        }

        // temp_map过滤str_map里面不同的key对应了相同的value的情况，
        // 这种情况也要返回false
        std::map<std::string, char> temp_map;
        for (auto iter = str_map.begin(); iter != str_map.end(); ++ iter) {
            temp_map[vec_str[iter->second]] = iter->first;
        }
        if (temp_map.size() != str_map.size()) {
            return false;
        }
        return true;
    }

    // 将str根据pat分隔字符串得到分离开的string数组
    int split(const std::string str, const char pat, vector<std::string>& vec_str)
    {
        size_t pos = 0, temp_pos = 0;
        do {
            temp_pos = str.find(pat, pos);
            vec_str.push_back(str.substr(pos, temp_pos - pos));
            pos = temp_pos + 1;
        } while (temp_pos != std::string::npos);
        return 0;
    }
};
```
