set去重，DFS遍历二叉树，当set大小大于1时，说明非单值，否则为单值

代码：
```
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        stack<TreeNode*> node;
        set<int> s;
        node.push(root);
        while (!node.empty()) {
            TreeNode* p = node.top();
            s.insert(p->val);
            if (s.size() > 1)
                return false;
            node.pop();
            if (p->left)
                node.push(p->left);
            if (p->right)
                node.push(p->right);
        }
        return true;
    }
};
```
