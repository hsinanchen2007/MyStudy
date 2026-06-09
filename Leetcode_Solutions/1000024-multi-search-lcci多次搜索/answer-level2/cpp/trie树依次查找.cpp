对smalls数组建立trie树，提升查找效率。

```
struct TrieNode {
    int id = -1;
    TrieNode* next[26];
};
class Solution {
public:
    vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
        TrieNode* root = new TrieNode();
        for(int i=0;i<smalls.size();i++) {
            add(root, smalls[i], i);
        }
        vector<vector<int>> res(smalls.size());
        for(int i=0;i<big.size();i++) {
            find(root, big, i, res);
        }
        return res;
    }

    void find(TrieNode* root, string& s, int i, vector<vector<int>>& res) {
        for(int j=i;j<s.size();j++) {
            root = root->next[s[j]-'a'];
            if(!root) return;
            if(root->id>=0) res[root->id].push_back(i);
        }
    }
    void add(TrieNode* root, string& s, int id) {
        for(char c: s) {
            if(root->next[c-'a']==NULL)
                root->next[c-'a'] = new TrieNode();
            root = root->next[c-'a'];
        }
        root->id = id;
    }
};
```
