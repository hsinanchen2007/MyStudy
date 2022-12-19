```
struct TrieNode {
    int len = 0;
    vector<TrieNode*> children;
    TrieNode() {
        children = vector<TrieNode*>(26);
    }
};
class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        TrieNode* root = new TrieNode();
        for(auto& w: words) add(root, w);
        string res = "";
        for(int i=0;i<S.size();) {
            int j = i+find(root, S, i), k=i;
            if(i==j) { res += S[i++]; continue; }
            while(++i<=j) j = max(j, i+find(root, S, i));
            res += "<b>" + S.substr(k, j-k) + "</b>";
            i = j;
        }
        return res;
    }
    int find(TrieNode* root, string& s, int i) {
        int len = 0;
        while(i<s.size() && root->children[s[i]-'a'] != NULL) {
            root = root->children[s[i++]-'a'];
            len = max(len, root->len);
        }
        return len;
    }
    void add(TrieNode* root, string& w) {
        for(char c: w) {
            if(root->children[c-'a']==NULL)
                root->children[c-'a'] = new TrieNode();
            root = root->children[c-'a'];
        }
        root->len = w.size();
    }
};
```
