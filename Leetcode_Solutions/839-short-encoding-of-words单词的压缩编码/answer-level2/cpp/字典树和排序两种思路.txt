
## 字典树

- 如果两个单词s和t，如果t是s的后缀，则t可以忽略
- 想到后缀树，即借用前缀树的模型，进行逆序插入单词
- 求解每一条路径的长度总和，BFS思路

![后缀字典树思路](https://pic.leetcode-cn.com/6747090751002455399d9e75661316015d1ea5133927c835f3d5b7867dac7051.png)

1. [”time”, "me", “bell”, “hime”]逆序后得到[”emit”, "em", “lleb”, “emih”]
2. 插入字典树
3. 求解字典树所有分支高度和; 4 + 4 + 4，再加3个分隔符‘#’的长度，得到15

### 代码实现

```cpp
struct treeNode {
    bool isEnd;
    treeNode *next[26];

    treeNode() {
        isEnd = false;
        memset(next, 0, sizeof(next));
    }
};

class Trie {
public:
    treeNode *root;
    Trie() {
        root = new treeNode();
    }

    void insert(const string &word) {
        treeNode *node = root;
        for (char c : word) {
            if (node->next[c - 'a'] == NULL) {
                node->next[c - 'a'] = new treeNode();
            }
            node = node->next[c - 'a'];
        }
        node->isEnd = true;
    }
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        if (words.empty()) return 0;
        for (int i = 0; i< words.size(); i++) reverse(words[i].begin(), words[i].end());

        Trie t = Trie();
        for (auto &word: words) t.insert(word);
        int ans = 0;
        queue<treeNode*> q;
        q.push(t.root);
        int level = 1;
        while (q.size()){
            int k = q.size();
            while (k--){
                auto cur = q.front();
                q.pop();
                bool isLeaf = true;
                for (int i = 0; i < 26; i++){
                    if (cur->next[i]) {
                        q.push(cur->next[i]);
                        isLeaf = false;
                    }
                }
                if (isLeaf) ans += level;
            }
            level ++ ;
        }
        return ans;
    }
};
```

## 字典序排序+去重

根据上面后缀字典树的思路，我们发现，其实只需要倒序后，进行字典序排序，忽略掉被包含的前缀单词，即可

### 代码实现

```cpp
class Solution {
public:
    static bool cmp(string& s1, string& s2){
        return s1 < s2;
    }
    int minimumLengthEncoding(vector<string>& words) {
        if (words.empty()) return 0;
        for (int i = 0; i< words.size(); i++){
            reverse(words[i].begin(), words[i].end());
        }
        sort(words.begin(), words.end(), cmp);
        int ans  = 0;
        for (int i = 0, j = 1; j < words.size(); i++, j++){
            if (words[i].size() <= words[j].size()) {
                if (words[i] == words[j].substr(0, words[i].size())) continue;
            }
            ans += words[i].size() + 1;
        }
        ans += words[words.size()-1].size() + 1;
        return ans;
    }
};
```



