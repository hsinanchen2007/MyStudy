### 解题思路
使用set做去重
使用哈希表保存电话号码和对应字母的映射
其他的，代码里应该说的很清楚了。

ps.
有时候这种题，开始写的时候思路不是很具体，大概知道方向，知道什么时候应该将字符串加入结果集，答案也就有了
其实比较关键的是写出dfs这种函数的声明，如果知道每个参数要干嘛，函数的定义也就比较简单了

### 代码

```cpp
class Solution {
public:
    void dfs(string& digits, int start, string tmp, set<string>& ans, unordered_map<char, vector<char>>& mp) {
        if (start == digits.size()) {
            ans.insert(tmp);
        }
        vector<char> characters = mp[digits[start]];
        for (int i = 0; i < characters.size(); i++) {
            dfs(digits, start + 1, tmp + characters[i], ans, mp);
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.size() == 0) {
            return result;
        }
        unordered_map<char, vector<char>> mp;
        mp['2'] = {'a', 'b', 'c'};
        mp['3'] = {'d', 'e', 'f'};
        mp['4'] = {'g', 'h', 'i'};
        mp['5'] = {'j', 'k', 'l'};
        mp['6'] = {'m', 'n', 'o'};
        mp['7'] = {'p', 'q', 'r', 's'};
        mp['8'] = {'t', 'u', 'v'};
        mp['9'] = {'w', 'x', 'y', 'z'};
        string tmp = "";
        set<string> ans;
        int start = 0;
        dfs(digits, start, tmp, ans, mp);
        // set里存放所有的字符串集合
        set<string>::iterator it;
        for (it = ans.begin(); it != ans.end(); it++) {
            result.push_back(*it);
        }
        return result;
    }
};
```