c++ 较为简洁的一个解法
```
class Solution {
public:
    struct TrieTree {
        bool flag;
        map<char, TrieTree*> next;
        TrieTree() : flag(false) {}
    };
    TrieTree* root;
    Solution() {
        root = new TrieTree();
    }
    
    string replaceWords(vector<string>& dict, string sentence) {
        TrieTree* node;
        for (auto w : dict) {
            node = root;
            for (auto x : w) {
                if ((node->next).count(x) == 0) {
                    node->next[x] = new TrieTree();
                }
                node = node->next[x];
            }
            node->flag = true;
        }
        string res;
        int start = 0;
        int end = 0;
        for (int i = 0; i < sentence.size(); ++i) {
            if (sentence[i] == ' ') 
                continue;
            node = root;
            start = i;
            while (i < sentence.size() && sentence[i] != ' ') {
                if (node->flag || node->next.count(sentence[i]) == 0) 
                    break;
                node = node->next[sentence[i]];
                ++i;
            }
            end = i;
            while (i < sentence.size() && sentence[i] != ' ') 
                ++i;
            if (!node->flag) 
                end = i;
            res += sentence.substr(start, end - start) + " ";
        }
        if (!res.empty())
            res.pop_back();
        return res;
    }
};
```
