既然要找最左边的，从右向左BFS就完事了，记录队列最后一个元素。
```c++
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode *t;
        q.push(root);
        while(!q.empty()){
                t=q.front();
                q.pop();
                if(t->right)
                    q.push(t->right);
                if(t->left)
                    q.push(t->left);
        }
        return t->val;
    }
};
```
