```
struct TrieNode {
    int val = 0;
    map<char, TrieNode*> children;
};
class AutocompleteSystem {
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        ans = "";
        cur = root = new TrieNode();
        // 构建trie树
        for(int i=0;i<sentences.size();i++) {
            add(sentences[i], times[i]);
        }
    }

    void add(string& s, int time) {
        TrieNode* node = root;
        for(char c: s) {
            if(node->children.find(c)==node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->val += time;
    }
    
    vector<string> input(char c) {
        // 输入结束时复位
        if (c == '#') {
            cur->val++;
            cur = root;
            ans = "";
            return {};
        }
        // 更新当前节点
        if(cur->children.find(c)==cur->children.end()) {
            cur->children[c] = new TrieNode();
        }
        cur = cur->children[c];
        ans += c;
        // 查找所有符合条件的候选集及出现次数
        vector<pair<string, int>> vec;
        find(cur, ans, vec);
        // 按次数及字典序排序
        sort(vec.begin(), vec.end(), [this](pair<string, int>& p1, pair<string, int>& p2){
            return p1.second == p2.second ? compare(p1.first, p2.first) : p1.second > p2.second; 
        });
        // 取top 3
        vector<string> res;
        for(auto& p: vec) {
            res.push_back(p.first);
            if(res.size()>=3) break;
        }
        return res;
    }
    // 字典序比较
    bool compare(string& s1, string& s2) {
        int i = 0, m = s1.size(), n = s2.size();
        while(i<m&&i<n) {
            if(s1[i] != s2[i]) {
                return s1[i] < s2[i];
            }
            i++;
        }
        return m <= n;
    }
    // dfs查找所有候选集及次数
    void find(TrieNode* node, string ans, vector<pair<string, int>>& vec) {
        if(node->val>0) {
            vec.push_back({ans, node->val});
        }
        for(auto& it: node->children) {
            find(it.second, ans+it.first, vec);
        }
    }
private:
    TrieNode* root;
    TrieNode* cur;  // 当前节点
    string ans = "";  // 历史输入
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
```
