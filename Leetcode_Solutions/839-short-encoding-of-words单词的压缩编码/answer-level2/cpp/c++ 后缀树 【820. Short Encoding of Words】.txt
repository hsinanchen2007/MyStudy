### 解题思路
1. 先对vector<string>& words排序，保证长的在前面
2. 依次到后缀树中查询，如果在后缀树中则跳过。
3. 如果不在树中，则插入后缀树并将size+1加到最终结果上

### 代码

```cpp
class Solution {
public:
    struct Node {
        vector<Node*> next;
        Node() { next.resize(26, 0); }
    };

    Node *root = new Node();

    void add(string& str) {
        Node* q = root;
        for (int i = str.size()-1; i >= 0; --i) {
            char val = str[i] - 'a';
            if (!q->next[val]) q->next[val] = new Node(); 
            q = q->next[val];
        }
    }

    bool findPost(string& str) {
        Node* q = root;
        for (int i = str.size()-1; i >= 0; --i) {
            char val = str[i] - 'a';
            if (!q->next[val]) return false;
            q = q->next[val];
        }
        return true;
    }

    int minimumLengthEncoding(vector<string>& words) {
        int result = 0;
        sort(words.begin(), words.end(), [](const string& x, const string& y) {
            return x.size() > y.size();
        });
        for (auto& str : words) {
            if (findPost(str)) continue;
            result += str.size()+1;
            add(str);
        }
        return result;
    }
};
```