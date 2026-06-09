![image.png](https://pic.leetcode-cn.com/41f6d3eb0784733e58aa7b87d5e849c4e2f07b6317982149cd7e08d38bd6b82c-image.png)
不能像C++那样直接使用abs来处理，C语言需要使用fabs函数；
```
int closestValue(struct TreeNode* root, double target){
    double l = root->val;
    double r = root->val;
    while (root) {
        if (root->val > target) {
            r = root->val;
            root = root->left;
        }else if (root->val < target) {
            l = root->val;
            root = root->right;
        }else {
            return root->val;
        }
    }
    return fabs(target - l) < fabs(r - target) ? l : r;
}
```
