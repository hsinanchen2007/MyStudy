```
class FileSystem {
public:
    struct TrieNode {
        int val;
        map<string, TrieNode*> next;
        TrieNode(int v) : val(v) {}
    };
    TrieNode* root;
    FileSystem() {
        root = new TrieNode(0);
    }
    vector<string> splitPath(const string& path, char sep) {
        vector<string> res;
        if (path.empty() || path == "/" || path[0] != '/')
            return res;
        string w;
        for (int i = 1; i < path.size(); ++i) {
            if (path[i] == '/') {
                res.push_back(w);
                w.clear();
            } else {
                w += path[i];
            }
        }
        res.push_back(w);
        return res;
    }
    TrieNode* searchTree(const vector<string>& words) {
        if (words.empty())
            return NULL;
        TrieNode* node = root;
        for (int i = 0; i < words.size() - 1; ++i) {
            if (node->next.count(words[i]) == 0)
                return NULL;
            node = node->next[words[i]];
        }
        return node;
    }
    bool create(string path, int value) {
        vector<string> words = splitPath(path, '/');
        TrieNode* node = searchTree(words);
        if (node == NULL)
            return false;
        node->next[words.back()] = new TrieNode(value);
        return true;
    }
    int get(string path) {
        vector<string> words = splitPath(path, '/');
        TrieNode* node = searchTree(words);
        if (node == NULL)
            return -1;
        if (node->next.count(words.back()) == 0)
            return -1;
        return node->next[words.back()]->val;
    }
};
```