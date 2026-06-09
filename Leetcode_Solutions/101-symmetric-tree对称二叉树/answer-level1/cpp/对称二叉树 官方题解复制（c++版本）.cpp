
递归法：

```c++[]
class Solution {
public:
    bool ismirror(TreeNode* left,TreeNode* right)
    {
        
        if(left==NULL&&right==NULL) return true;
        if(right==NULL||left==NULL) return false;
        
        return (left->val==right->val)&&ismirror(left->left,right->right)&&ismirror(left->right,right->left);
        
    }
    bool isSymmetric(TreeNode* root) {
        return ismirror(root,root);
    }
};
```
迭代法
```c++ []
class Solution {
public:
    
    bool isSymmetric(TreeNode* root) {
         queue<TreeNode*> q;
        q.push(root);
        q.push(root);
        while (!q.empty())
        {
            TreeNode* t1 = q.front();
            q.pop();
            TreeNode* t2 = q.front();
            q.pop();
            if (t1 == NULL && t2 == NULL) continue;
            if (t1 == NULL || t2 == NULL) return false;
            if (t1->val != t2->val) return false;
            q.push(t1->left);
            q.push(t2->right);
            q.push(t1->right);
            q.push(t2->left);
        }
        return true;
    }
};
static const auto io_speed_up=[]{
    ios::sync_with_stdio(false);
    cin.tie();
    return 0;
}();
```