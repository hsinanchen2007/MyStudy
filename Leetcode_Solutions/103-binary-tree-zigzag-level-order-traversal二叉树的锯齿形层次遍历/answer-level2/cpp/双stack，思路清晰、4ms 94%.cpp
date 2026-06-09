当我们从左往右遍历的时候，需要优先保存节点的左节点，然后才是右节点。因为根据题目，我们下一次是从右往左遍历，即需要优先读取的是节点的右子节点，然后才是左子节点。
相反，我们从左往右遍历时，优先保存节点的右子节点，然后到左子节点。所以只需要两个stack即可完成操作。

最后执行代码的时候还碰到了一个小问题，就是应该需要加**判断条件**再进入**右往左**读取的过程，否则由于代码最后还有一个res.push_back(mid);就会出现结果有个空的vector出现。这个问题会在最后一步执行的是左往右循环后出现，因此我增加一个进入条件。
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        //借助stack
        vector<vector<int>> res;
        if(root == nullptr)
            return res;
        
        stack<TreeNode*> l;//左往右
        stack<TreeNode*> r;//右往左
        l.push(root);
        while(!l.empty() || !r.empty()) {
            vector<int>mid;
            while(!l.empty()) {
                TreeNode* p = l.top(); l.pop();
                mid.push_back(p->val);
                if(p->left != nullptr)
                    r.push(p->left);
                if(p->right != nullptr)
                    r.push(p->right);
            }
            res.push_back(mid);
            mid.clear();
            if(!r.empty()) {
                while(!r.empty()) {
                    TreeNode* p = r.top(); r.pop();
                    mid.push_back(p->val);
                    if(p->right != nullptr)
                        l.push(p->right);
                    if(p->left != nullptr)
                        l.push(p->left);
                }
                res.push_back(mid);
                mid.clear();
            }
        }
        return res;
    }
};
```
