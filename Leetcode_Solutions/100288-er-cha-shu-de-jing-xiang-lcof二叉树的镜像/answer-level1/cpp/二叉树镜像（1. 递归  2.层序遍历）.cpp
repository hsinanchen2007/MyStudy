# 一、递归
1. 我们定义一个函数，接受一个节点node参数,功能为：镜像从该节点开始的子树，并返回该节点。（退出条件为该node节点为空）
2. 函数内部分别对左右子节点调用该方法，并把返回的节点交换位置即可。
```
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        // 退出条件
        if (!root) return nullptr;
        
        // 分别对左右子树镜像,并交换左右子树
        TreeNode *temp = root->right;
        root->right = mirrorTree(root->left);
        root->left = mirrorTree(temp);
        
        return root;
    }
};
```
# 二、层序遍历
1. 使用队列实现层序遍历。
2. 在从队列中拿出node时，交换左右子节点即可。
```
class Solution {
public:
    void _swap(TreeNode *node) {
        if (!node) return;
        TreeNode *temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
    
    TreeNode* mirrorTree(TreeNode* root) {
        if (!root) return nullptr;
        
        TreeNode *temp;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty()) {
            temp = que.front();
            que.pop();
            _swap(temp);
            if (temp->left) que.push(temp->left);
            if (temp->right) que.push(temp->right);
        }
        return root;
    }
};
```
