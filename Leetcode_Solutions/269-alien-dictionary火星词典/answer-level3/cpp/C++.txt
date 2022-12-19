### 解题思路
思路都在注释中
开始想不出来，看答案才知道是拓扑排序相关知识

### 代码

```cpp
class Solution {
public:
    string alienOrder(vector<string>& words) {
        // 1. 使用一个unordered_map保存图
        unordered_map<char, set<char>> mp;
        // 遍历每个单词
        for (int i = 0; i < words.size() - 1; i++) {
            //　遍历相邻单词的每个位
            int j = 0;
            for (j = 0; j < words[i].size() && j < words[i+1].size(); j++) {
                if (words[i][j] == words[i+1][j]) {
                    // 字符相同直接跳过
                    continue;
                }
                // 不同的话构造图
                if (mp.count(words[i][j])) {
                    mp[words[i][j]].insert(words[i+1][j]); 
                } else {
                    set<char> s;
                    s.insert(words[i+1][j]);
                    mp[words[i][j]] = s;
                }
                break; // 只能判断第一个不同字符的顺序关系，不能判断其他
            }

            if (j == words[i+1].size() && j < words[i].size()) {
                // 考虑["abc", "ab"]这种输入
                return "";
            }
        }

        // 2. 处理入度, 初始化为-1
        vector<int> indegrees(26, -1);

        // 对于单词里出现的每个字符，赋值为０;

        for(string word : words) {
            for (char ch : word) {
                indegrees[ch - 'a'] = 0;
            }
        }

        // 对图里所有value(set)字符，计算入度
        unordered_map<char, set<char>>::iterator it;

        for (it = mp.begin(); it != mp.end(); it++) {
            set<char> chs = it->second;
            for (char c : chs) {
                indegrees[c - 'a']++;
            }
        }
        // count 统计有多少字符
        // list 保存入度为０的字符，可以理解成这样的字符：每个阶段没有其他字符指向该字符
        queue<char> list;
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (indegrees[i] != -1) {
                count++;
            }
            if (indegrees[i] == 0) {
                list.push('a' + i);
            }
        }
        string result = "";
        while (!list.empty()) {
            char c = list.front();
            result += c;
            list.pop();
            // 删除一个字符，要将其指向的所有字符的入度-1
            if (mp.count(c)) {
                set<char> cs = mp[c];

                for (char ch : cs) {
                    indegrees[ch - 'a']--; 
                    if (indegrees[ch - 'a'] == 0) {
                        // 有新的入度为０的节点
                        list.push(ch);
                    }
                }
            } 
        }
        if (count != result.size()) {
            return "";
        }
        return result;
    }
};
```