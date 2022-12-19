### 解题思路
1.使用istringstream分割str。
2.将pattern和str分别映射自己的index。
3.最终比较index是否相互对应来表示是否单词规律相同。

### 代码

```cpp
class Solution {
private:
    template<typename T>
    vector<char> symbolize(const vector<T>& v){
        char index = '@';
        unordered_map<T,char> dict;
        vector<char> ans;
        for(const auto& item : v){
            if(!dict.count(item)) dict[item] = index++;
            ans.push_back(dict[item]);
            }
        return ans;
    }
    
    vector<string> split_by_space(const string& str){
        vector<string> ans;
        istringstream is(str);
        string s;
        while(is >> s) ans.push_back(s);
        return ans;
    }
public:
    bool wordPattern(string pattern, string str) {
        vector<char> v_pattern(pattern.begin(),pattern.end());
        vector<string> v_str = split_by_space(str);
        return symbolize(v_pattern) == symbolize(v_str);
    }
};
```