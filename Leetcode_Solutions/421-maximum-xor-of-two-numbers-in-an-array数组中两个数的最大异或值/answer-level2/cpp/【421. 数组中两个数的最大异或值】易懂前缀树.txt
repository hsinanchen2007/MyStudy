## 思路一：Trie树
1. 构建前缀树
2. 对每个数在前缀树中查找异或最大值
### 代码
```c++
struct TrieNode {
    TrieNode *children[2];
    TrieNode() {
        for (auto &child : children) child = nullptr;
    }
};
class Solution {
public:
    Solution() {
        root = new TrieNode();
    }

    void insert(int n) {               
        TrieNode *cur = root;
        for (int j = 31; j >= 0; j--) {
            int index = (n >> j) & 1;
            if (cur->children[index] == nullptr) {
                cur->children[index] = new TrieNode();
            }                
            cur = cur->children[index];
        }                
    }
       
    int findMaximumXOR(vector<int>& nums) {
        for (const auto n : nums) {
            insert(n);
        }
        int res = 0;
        for (const auto n : nums) {
            int tmp = 0;
            TrieNode *cur = root;
            for (int i = 31; i >= 0; i--) {
                int index = (n >> i) & 1;
                if (cur->children[!index] != nullptr) {//选择不同值使异或最大
                    tmp += 1 << i;
                    cur = cur->children[!index];
                } else {
                    cur = cur->children[index];
                }
            }
            res = max(res, tmp);
        }        
        return res;
    }
private:
    TrieNode *root;
};
```
