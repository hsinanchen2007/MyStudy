一个if-else就可以解决
如果两个指针都不为nullptr,则递归判断
否则，必须两者均为nullptr才是同一二叉树，一个nullptr一个不是必然不满足条件，所以直接return p == q
```C++
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p && q) {
            return p->val == q->val && 
                   isSameTree(p->left, q->left) &&
                   isSameTree(p->right, q->right);
        } else {
            return p == q;
        }
    }
};
```
