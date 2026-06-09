参考了各位大佬的意见，总结了常规易懂c++写法：BFS的同时构造路径，dfs利用路径构造答案vector<vector<string>> allPath
写法更加单易懂，变量名，代码风格符合编程规范。
```
代码块
#include <vector>
#include <cstdlib>
#include <climits>
#include <queue>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
    
public:
    bool canMatch(string& str1, string& str2)
    {
        int cnt = 0;
        for(int i = 0; i < str1.size(); i++) {
            if (str1[i] != str2[i]) {
                cnt++;
            }
        }
        if (cnt == 1) {
            return true;
        }
        return false;
    }

    struct item {
        string str;
        int deep;
        item(string _s, int _d) : str(_s), deep(_d) {
        }
    };

    void dfs(string beginWord, string toTrace, unordered_map<string, vector<string>>& reflex, vector<string> path, vector<vector<string>>& allPath)
    {
        if (toTrace == beginWord) {
            path.push_back(toTrace);
            reverse(path.begin(), path.end());
            allPath.push_back(path);
            return;
        }
        path.push_back(toTrace);
        for (auto &i : reflex[toTrace]) {
            dfs(beginWord, i, reflex, path, allPath);
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord == "" || endWord == "" || wordList.size() == 0) {
            return {};
        }
        queue<item> save;
        unordered_map<string, int> allSave;
        unordered_map<string, vector<string>> reflex; 
        vector<vector<string>> allPath;
        bool findEnd = false;
        save.push(item(beginWord, 1));
        allSave.insert(pair<string, int>(beginWord, 1));
        while (save.empty() != true) {
            item now = save.front();
            save.pop();
            if (now.str == endWord) {
                findEnd = true;
                break;
            }
            for (int i = 0; i < wordList.size(); i++) {
                if (canMatch(now.str, wordList[i])) {
                    if (allSave.find(wordList[i]) == allSave.end()) {
                        save.push(item(wordList[i], now.deep + 1));
                        allSave.insert(pair<string, int>(wordList[i], now.deep + 1));
                        reflex[wordList[i]].push_back(now.str);
                    } else {
                        if (allSave[wordList[i]] <= now.deep)  {
                            continue;
                        } else {
                            reflex[wordList[i]].push_back(now.str);
                        }
                    }
                }
            }
        }
        if (!findEnd) {
            return {};
        }
        dfs(beginWord, endWord, reflex, {}, allPath);
        return allPath;
    }
};
```

