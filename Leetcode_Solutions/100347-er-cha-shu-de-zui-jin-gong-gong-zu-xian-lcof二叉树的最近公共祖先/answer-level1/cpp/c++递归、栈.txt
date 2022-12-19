分别找出从根节点到目标节点的路径，存放到栈内。两个栈的栈顶的相同节点为公共节点。越往里层次越低。
```
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || p == NULL ||q == NULL)
        {
            return NULL;
        }
        stack<TreeNode*> path_p;
        find_path(root, p, path_p);
        stack<TreeNode*> path_q;
        find_path(root, q, path_q);
        TreeNode* res = root;
        while (!path_p.empty() && !path_q.empty())
        {
            if (path_p.top() == path_q.top())
            {
                res = path_p.top();
                path_p.pop();
                path_q.pop();
            }
            else
            {
                break;
            }
        }
        return res;
    }
    bool find_path(TreeNode* r, TreeNode* p, stack<TreeNode*> &path_p)
    {
        if (r == NULL)
        {
            return false;
        }
        if (r == p)
        {
            return true;
        }
        bool left = find_path(r->left, p, path_p);
        if (left)
        {
            path_p.push(r->left);
            return true;
        }
        bool right = find_path(r->right, p, path_p);
        if (right)
        {
            path_p.push(r->right);
            return true;
        }
        return false;
    }
};
```
