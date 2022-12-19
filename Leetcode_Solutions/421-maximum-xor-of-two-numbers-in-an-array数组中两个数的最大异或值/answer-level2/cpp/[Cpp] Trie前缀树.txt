### 解题思路
将每个数转换成二进制后存入前缀树，存之前先计算当前树中与下一次要存的数的最大异或值

### 代码

```cpp
class TrieNode {
public:
    int num;
    TrieNode* nextNode[2] = {NULL};
    TrieNode() {
        num = 0;
    }
};


class Trie {
private:
    TrieNode* head;
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
        head = root;
    }
    
    void insert(int n) {
        root = head;
        for (int i = 31; i >= 0; i--) {
            bool now = ((n) & (1<<i));
            if (root->nextNode[now] == NULL)
                root->nextNode[now] = new TrieNode();
            root = root->nextNode[now];
        }
        root->num = n;
    }
    
    int search(int n) {
        root = head;
        for (int i = 31; i >= 0; i--) {
            bool now = ((n) & (1 << i));
            if (root->nextNode[1 - now] != NULL)
                root = root->nextNode[1 - now];
            else if (root->nextNode[now] != NULL)
                root = root->nextNode[now];
        }
        return (root->num) ^ (n);
    }
    
};


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* obj = new Trie();
        obj->insert(nums[0]);
        int res = 0;
        for (int i = 1; i < nums.size(); i++) {
            int val = obj->search(nums[i]);
            res = max(res, val);
            obj->insert(nums[i]);
        }
        return res;
    }
};
```