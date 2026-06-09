220ms + 226.9M 击败97.79%用户

首先创建前缀树，这个不必多说。
创建好了以后，遍历字符串数组在前缀树中搜索，具体的规则为：
从root开始搜索，每当搜到单词结束的时候（节点IsEnd为true），单词搜索数量+1，将  “搜索位置+1” 和 “单词搜索数量” 递归进行下次一次搜索，如果递归的结果为false，那么把单词搜索数量-1。最后判断搜索结果。代码如下：

```
struct Node {
    bool isEnd;
    Node *next[26]{nullptr};

    Node() : isEnd(false) {}
};

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
        Node *root = new Node();
        for (auto word:words) {
            Node *tmp = root;
            for (auto i = 0; i < word.size(); i++) {
                if (tmp->next[word[i] - 'a'] == nullptr) {
                    tmp->next[word[i] - 'a'] = new Node;
                }
                tmp = tmp->next[word[i] - 'a'];
            }
            tmp->isEnd = true;
        }

        vector<string> rst;
        for (auto word : words) {
            int cnt = 0;
            if (FindInRoot(root, word, 0, cnt)) {
                if (cnt >= 2) {
                    rst.push_back(word);
                }
            }
        }

        return rst;

    }

    bool FindInRoot(Node *node, string &s, int location, int &cnt) {
        Node *tmp = node;
        for (; location < s.size(); location++) {
            if (tmp->next[s[location] - 'a'] != nullptr) {
                tmp = tmp->next[s[location] - 'a'];
            } else {
                return false;
            }
            if (tmp->isEnd) {
                cnt++;
                if (location == s.size() - 1) {
                    return true;
                }
                if (FindInRoot(node, s, location + 1, cnt)) {
                    return true;
                }
                cnt--;
            }
        }
        return false;
    }

};
```
