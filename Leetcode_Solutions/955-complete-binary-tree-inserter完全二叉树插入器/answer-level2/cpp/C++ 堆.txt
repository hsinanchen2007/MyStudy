### 解题思路
不知道为什么他们都用队列，用堆不好吗？

### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
    vector<TreeNode*> _data;
public:
    void init(TreeNode* root, int idx) {
        if(!root) return;
        if(_data.size() <= idx) _data.resize(idx + 1, NULL);
        _data[idx] = root;
        init(root->left, 2 * idx + 1);
        init(root->right, 2 * idx + 2);
    }

    CBTInserter(TreeNode* root) {
        init(root, 0);
    }
    
    int insert(int v) {
        TreeNode* cur = new TreeNode(v);
        _data.push_back(cur);
        
        TreeNode* p = _data[_data.size() / 2 - 1];
        if(p->left) p->right = cur;
        else p->left = cur;

        return p->val;
    }
    
    TreeNode* get_root() {
        return _data.size() > 0 ? _data[0] : NULL;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
```