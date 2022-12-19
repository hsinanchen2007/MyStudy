没有看到C++用迭代实现的，发一下自己写的，用的层序遍历和bfs
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
class Solution {
public:
    bool isSubStructureCore(TreeNode* tmp, TreeNode* B) {
        queue<TreeNode*> q1;
        q1.push(tmp);
        queue<TreeNode*> q2;
        q2.push(B);
        while (!q1.empty() && !q2.empty())
        {
            TreeNode* tmp1 = q1.front();
            q1.pop();
            TreeNode* tmp2 = q2.front();
            q2.pop();
            if (tmp1 -> val != tmp2 -> val)
                return false;
            if (tmp2 -> left)
                if (tmp1 -> left)
                {
                    q1.push(tmp1 -> left);
                    q2.push(tmp2 -> left);
                }
                else
                    return false;
            if (tmp2 -> right)
                if (tmp1 -> right)
                {
                    q1.push(tmp1 -> right);
                    q2.push(tmp2 -> right);
                }
                else
                    return false;
        }
        return true;
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == NULL || B == NULL)
            return false;
        queue<TreeNode*> q;
        q.push(A);
        while (!q.empty())
        {
            TreeNode* tmp = q.front();
            q.pop();
            if (tmp -> val == B -> val && isSubStructureCore(tmp, B))
                return true;
            if (tmp -> left)
                q.push(tmp -> left);
            if (tmp -> right)
                q.push(tmp -> right);
        }
        return false;

    }
};
```
