写了个队列的解法，结果过不了[1,2]用例。
OK,fine~ 不给面子那就直接递归吧，暴力美学，三行解决：
```
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int a = minDepth(root->left), b = minDepth(root->right);
        return 1 + (a == 0 || b == 0 ? (b == 0 ? a : b) : (a < b ? a : b));
    }
};
```
