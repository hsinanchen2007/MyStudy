### 字符串贪心匹配

* 先对给定的words字符串数组中的字符串根据其长度排序
* 然后对于排好序的每个字符串来说，在索引字符串s中找是否包含(自身#）,若找不到，则添加(自身#)到索引字符串s结尾
* 最后索引字符串的长度即为答案


```cpp
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.length() > b.length();
        });
        string s = "";
        for (string &word : words) {
            string t = word + "#";
            if (s.find(t) == string::npos) {
                s += t;
            }
        }
        return s.length();
    }
};
```

### 字典树方法

* 构建一个后缀树，把每个字符的后缀放入字典树，并且要注意在字典树的节点上要添加上这个节点的深度，也就是这个字符在所在字符串中倒数第几个节点
* 使用一个哈希表，统计字典树最后一个节点的深度+1(要算上#号)，把他们全部加起来。（因为没有下一个字符了，字典树的尾节点的性质为next数组为空）

```cpp
struct TrieNode {
    int depth = 0;
    unordered_map<char, TrieNode*> next;
    TrieNode(int depth): depth(depth){}
};

class Trie {
private:
    TrieNode *root;
    vector<TrieNode*> memo;

public:
    Trie(): root(new TrieNode(0)) {}
    
    void insert(const string& word) {
        TrieNode *p = root;
        for (int i = word.length() - 1; i >= 0; i--) {
            char c = word[i];
            if (!p->next.count(c)) {
                TrieNode *node = new TrieNode(p->depth + 1);
                p->next[c] = node;
                memo.push_back(node);
            }
            p = p->next[c];
        }
    }
    
    int cal() {
        int ret = 0;
        for (const auto& p : memo) {
            if (p->next.empty()) {
                ret += p->depth + 1;
            }
        }
        return ret;
    }
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        Trie trie;
        for (const string& word : words) {
            trie.insert(word);
        }
        return trie.cal();
    }
};
```