非递归确实是麻烦很多。。我也不确定这样写非递归是否简洁，不过使用队列层次遍历确实是蛮方便的。
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if ((!p && q) || (p && !q)) return 0;
        else if (!p && !q) return 1;
        if (p->val != q->val) return 0;
        queue<TreeNode*> tmpp, tmpq;
        TreeNode *t1, *t2;
        tmpp.push(p);
        tmpq.push(q);
        while (!tmpq.empty()) {
            t1 = tmpp.front();
            t2 = tmpq.front();
            if (t1->val != t2->val) return 0;
            tmpp.pop();
            tmpq.pop();
            if ((!t1->left && t2->left) || (t1->left && !t2->left)) return 0;
            else if (t1->left && t2->left) {
                tmpp.push(t1->left);
                tmpq.push(t2->left);
            }
            if ((!t1->right && t2->right) || (t1->right && !t2->right)) return 0;
            else if (t1->right && t2->right) {
                tmpp.push(t1->right);
                tmpq.push(t2->right);
            }
        }
        return 1;
    }
};
```