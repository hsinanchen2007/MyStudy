利用队列实现头部删除过时的父节点，尾部添加新增子节点，循环往复
```
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
public:
    TreeNode* root;
    queue<TreeNode*> q;
    int turn; // 记录当前可插入的是左侧还是右侧，0为左，1为右
    CBTInserter(TreeNode* node) {
        this->root = node;
        q.push(root);
        while (!q.empty()) {
            int s = q.size();
            bool hit_end = false;
            for (int i = 0; i < s; ++i) {
                auto p = q.front();
                if (p->left) {
                    q.push(p->left);
                } else {
                    turn = 0;
                    hit_end = true;
                    break;
                }
                if (p->right) {
                    q.push(p->right);
                } else {
                    turn = 1;
                    hit_end = true;
                    break;
                }
                q.pop();
            }
            if (hit_end) break;
        }
    }
    
    int insert(int v) {
        auto node = q.front();
        if (turn == 1) {
            node->right = new TreeNode(v);
            q.push(node->right);
            q.pop();
        } else {
            node->left = new TreeNode(v);
            q.push(node->left);
        }
        turn ^= 1;
        return node->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
```

![image.png](https://pic.leetcode-cn.com/fe5e4cc887575950d8de5c158783a0b61486bed503470de735f7334e54f0b8fb-image.png)
