### 解题思路
① 计算x、y结点的高度，判断高度是否相等；
② 判断x、y结点是否是“亲兄弟”；

### 代码

```cpp
class Solution {
private:
    int height_x(TreeNode *root, int x) {
        if (!root)
            return 9999;
        if (root->val == x)
            return 1;
        return min(1 + height_x(root->left, x), 1 + height_x(root->right, x));
    }

    int height_y(TreeNode *root, int y) {
        if (!root)
            return 9999;
        if (root->val == y)
            return 1;
        return min(1 + height_x(root->left, y), 1 + height_x(root->right, y));
    }

    bool samefather(TreeNode *root, int x, int y) {
        if (!root)
            return false;
        if (root->left && root->right) {
            if ((root->left->val == x && root->right->val == y)
                || (root->right->val == x && root->left->val == y))
                return true;
        }
        return samefather(root->left, x, y) || samefather(root->right, x, y);
    }

public:
    bool isCousins(TreeNode *root, int x, int y) {
        if (!root)
            return false;
        int hx = height_x(root, x);
        int hy = height_y(root, y);
        if (hx != hy)
            return false;
        return !samefather(root, x, y);
    }
};
```