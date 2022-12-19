### 解题思路
如果写过一两个前缀树的例子，这个题就没有一点难度了，实际上就是一棵简单的前缀树。

### 代码

```cpp
const int SIZE = 26;
struct Node{
    bool is_word;
    Node *next[SIZE];
    Node():is_word(false){};
};

class Trie{
private:
    Node *root;
    vector<vector<char>> maps;

public:
    Trie(){
        root = new Node();
        for(int i = 0; i < SIZE; i++) root->next[i] = nullptr;
        maps.resize(10);
        maps[0] = {'_'};
        maps[1] = {'!', '@', '#'};
        maps[2] = {'a', 'b', 'c'};
        maps[3] = {'d', 'e', 'f'};
        maps[4] = {'g', 'h', 'i'};
        maps[5] = {'j', 'k', 'l'};
        maps[6] = {'m', 'n', 'o'};
        maps[7] = {'p', 'q', 'r', 's'};
        maps[8] = {'t', 'u', 'v'};
        maps[9] = {'w', 'x', 'y', 'z'};
    }

    void insert(const string &str){
        Node *p = root;
        for(const char &c: str){
            int cnt = c - 'a';
            if(p->next[cnt] == nullptr){
                Node *node = new Node();
                for(int i = 0; i < SIZE; i++) node->next[i] = nullptr;
                p->next[cnt] = node;
            }
            p = p->next[cnt];
        }
        p->is_word = true;
    }

    vector<string> get_input(const string &str){
        if(str.empty()) return vector<string>();
        vector<string> ans;
        string temp;
        travel(root, str, 0, temp, ans);
        return ans;
    }

    void travel(Node *p, const string &str, const int &index, string &temp, vector<string> &ans){
        if(index == str.size()){
            if(p->is_word) ans.push_back(temp);
            return;
        }

        for(const char &c: maps[str[index]-'0']){
            int cnt = c - 'a';
            if(p->next[cnt] != nullptr){
                temp.push_back(c);
                travel(p->next[cnt], str, index+1, temp, ans);
                temp.pop_back();
            }
        }
    }
};

class Solution {
public:
    vector<string> getValidT9Words(string num, vector<string>& words) {
        Trie *trie = new Trie();
        for(const string &str: words){
            trie->insert(str);
        }

        return trie->get_input(num);
        // return vector<string>();
    }
};
```