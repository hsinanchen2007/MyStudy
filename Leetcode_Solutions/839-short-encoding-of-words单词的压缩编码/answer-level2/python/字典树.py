### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        words = sorted(words, key=lambda i: len(i), reverse=True)
        s = ''
        for i in words:
            if i+'#' in s:
                continue
            s += i+'#'
        return len(s)
```
字典树：
```C++
struct Node{
    Node* children[26];
    int isLeaf;
    Node(){
        isLeaf = 1;
        for(int i=0; i < 26; ++i){
            children[i] = nullptr;
        }
    }
};
class Solution {
public:
    void Insert(Node* root, const string& s, const int& pos){
        if(pos < 0) return;
        int t = s[pos] - 'a';
        if(root->children[t] == nullptr){
            root->children[t] = new Node();
        }
        if(pos == 0){
            root->isLeaf = 1;
        }
        Insert(root->children[t], s, pos-1);
    }
    int Count(Node* root, const int edgecnt){
        int sum = 0;
        int leaf = 1;
        for(int i=0; i<26; ++i){
            if(root->children[i] != nullptr){
                sum += Count(root->children[i], edgecnt+1);
                leaf = 0;
            }
        }
        if(leaf){
            return edgecnt + 1;
        }
        return sum;
    }

    int minimumLengthEncoding(vector<string>& words) {
        Node* root = new Node();
        for(auto word = words.begin(); word != words.end(); ++word){
            Insert(root , *word, word->size()-1);
        }
        return Count(root, 0);
    }
};
```