```c++
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
    queue<TreeNode*> que;
    // 注意root为一个完全二叉树
    CBTInserter(TreeNode* root) : root_(root), node_(nullptr) {
        que.push(root_);
        while(!que.empty()) {
            TreeNode* tmp = que.front();
            que.pop();
            if (tmp->left)  que.push(tmp->left);
            if (tmp->right) que.push(tmp->right);
            if (node_ == nullptr && (tmp->left == nullptr || tmp->right == nullptr)) {
                node_ = tmp;
                break;
            }
        }
    }
    
    int insert(int v) {
        TreeNode* newNode = new TreeNode(v);
        int father = node_->val;
        if(node_->left == nullptr) node_->left = newNode;
        else {
            node_->right = newNode;
            if (!que.empty()) {
                node_ = que.front();
                que.pop();
            } 
        }  
        return father;
    }
    
    TreeNode* get_root() {
        return root_;
    }
private:
    TreeNode* node_;   // 用来储存待插入节点的位置
    TreeNode* root_;   // 用来储存树根节点的位置
};
```