基本等于暴力

```
class Solution {
public:

    struct trie {
        int cnt;
        map<char, trie*> next;
        trie() : cnt(0) {}
    };
    trie* root;
    
    void buildTrie(string& s, int& ans) {
        root = new trie();
        for (int i = 0; i < s.size(); ++i) {
            trie* tmp = root;
            for (int j = i; j < s.size(); ++j) {
                char k = s[j];
                if (!tmp->next.count(k)) {
                    tmp->next[k] = new trie();
                }
                tmp = tmp->next[k];
                tmp->cnt++;
                if (tmp->cnt > 1) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
    }

    int longestRepeatingSubstring(string s) {
        int ans = INT_MIN;
        buildTrie(s, ans);
        return ans == INT_MIN ? 0 : ans;
    }
};

```
