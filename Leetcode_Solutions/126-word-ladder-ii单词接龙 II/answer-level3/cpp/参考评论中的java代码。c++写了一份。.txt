
- 和127题类似。不过这题需要把所有最短的给找出来，难度明显增加了。我们先像127题一样

- 使用双向bfs 找到最短的序列，并且引入了一个标志flag。默认是0.一旦找到那个最短序列后赋值为1。

- 使用unordered_map<string, vector<string>>来记录单词的记录，string是开始查找的单词，
  
- vector<string>是由这个 string改变一个字母且存在与字典中的集合。例如"hit"对应的就是 vector<string>{"hot"} 。

- 其中flag2表示begin方向和end方向是否有交换，每次交换后需要反转flag2。

```
class Solution {
public:
    vector<vector<string>> res;
    unordered_map<string, vector<string>> hash;
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dirc(wordList.begin(), wordList.end());
        if (dirc.find(endWord) == dirc.end()) return res;
        unordered_set<string> beginw{beginWord};
        unordered_set<string> endw{endWord};
        int flag1 = 0, flag2 = 0;  //第一个是否找到最短序列标志, 第二个是否反转标志。
        
        while (!beginw.empty()) {
            unordered_set<string> tmp;
            for (auto str : beginw) dirc.erase(str);
            for (auto str : beginw) {
                for (int i = 0; i < str.size(); ++i) {
                    string s = str;
                    for (char j = 'a'; j <= 'z'; ++j) {
                        s[i] = j;
                        if (dirc.find(s) == dirc.end()) continue;
                        if (endw.find(s) != endw.end()) flag1 = 1;
                        else tmp.insert(s);
                        flag2 ? hash[s].push_back(str) : hash[str].push_back(s);
                    } 
                }
            }
            if (flag1) break;  //已经找到最短序列退出循环。
            if (tmp.size() <= endw.size()) 
                beginw = tmp;
            else {
                beginw = endw; endw = tmp; 
                flag2 = !flag2;  //这里需要使用！反转。
            }
        }
        vector<string> ans = {beginWord};
        dfs(ans, beginWord, endWord);
        return res;
    }
    
    void dfs(vector<string>& ans, string& begin, string& end) {
        if (begin == end) {
            res.emplace_back(ans);
            return;
        }
        if (hash.find(begin) == hash.end()) return;
        for (auto str : hash[begin]) {
            ans.emplace_back(str);
            dfs(ans, str, end);
            ans.pop_back();
        }
    }
};
```