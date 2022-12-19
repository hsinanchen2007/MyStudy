### 解题思路
建立字典树，然后逐字符遍历sentence，遍历时记录状态，然后根据状态执行下一步
一个挺麻烦的想法，还不如用stringstream来的快，不清楚性能瓶颈出现在哪里
时间复杂度O(N+K)，建立字典树花费O(K)的时间，其中K代表字典所有单词的长度和，遍历字符串花费O(N)
空间复杂度O(N+K)，字典树占用O(K)的空间，其中K代表最坏情况所有前缀都没出现在字典里，返回值占用O(N)

### 代码

```cpp
struct TrieNode {
    bool str;
    unordered_map<char, TrieNode*> child;
    TrieNode() : str(false) {}
    TrieNode(bool s) : str(s) {}
};

class Solution {
private:
    TrieNode* root = nullptr;
    TrieNode* cur = nullptr;
    void insert(string word) {
        // 插入单词建立字典树
        cur = root;
        for (char& c:word) {
            if (cur->child.count(c) == 0) {
                cur->child[c] = new TrieNode();
            }
            cur = cur->child[c];
        }
        cur->str = true;
    }
    bool hasNext(char c) {
        // 判断当前节点下是否还有下一个字符c
        // 出函数后cur指向下一个节点
        if (cur->child.count(c) == 0) {
            return false;
        }
        cur = cur->child[c];
        return true;
    }
    bool isStr() {
        // 返回当前节点是否为单词
        return cur->str;
    }
    void reset() {
        // 重置节点
        cur = root;
    }
public:
    string replaceWords(vector<string>& dict, string sentence) {
        root = new TrieNode(); // 初始化根节点
        string ret;
        for(auto& s:dict) insert(s); // 插入单词构建字典树
        reset();       // 重置cur节点
        int state = 0; // 初始状态为0
        for(auto& c:sentence) {
            if (c == ' ') {
                // 如果遇到空格，证明空格前面是单词，此时应该无条件重置状态
                ret.push_back(c);
                state = 0;
                reset();
                continue;
            }
            switch(state) {
                case 0:
                    // 状态0，首先推入字符，然后判断是否树中包含这个字符的下一个节点
                    ret.push_back(c);
                    if(hasNext(c)) {
                        // 如果包含，还需检查是否到达一个单词的节点，是的话状态置1
                        if (isStr()) {
                            state = 1;
                        }
                    } else {
                        // 否则字典中没有这个单词，状态置2
                        state = 2;
                    }
                    break;
                case 1:
                    // 当状态为1 证明在字典中找到最短的前缀，那么完全跳过这个单词后面的内容
                    continue;
                case 2:
                    // 状态2 证明没找到前缀，将单词完整推入ret
                    ret.push_back(c);
                    continue;
            }
        }
        return move(ret);
    }
};
/*
测试样例 过了这个都过了
["cat", "bat", "rat", "a"]
"the cattle was rattled by the battery bat the kiss cat died a app"
*/
```