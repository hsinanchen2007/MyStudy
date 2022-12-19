最无脑但是最容易想到的方法，他的结果是全部链在右边的，而且是按照先序遍历的。
那就先序遍历一次，把节点都存在数组里，然后依次修改就好了。。
但是好像无技术含量，这样写的话，这题都能算简单难度了。如果追求技术的话，还是推荐别的写法吧。

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
private:
    vector<TreeNode*> t;
public:
    void modify(TreeNode *p) {
        t.push_back(p);
        if (p->left) modify(p->left);
        if (p->right) modify(p->right);
        return;
    }
    void flatten(TreeNode* root) {
        if (root) modify(root);
        for (int i = 0; i < t.size(); ++i) {
            t[i]->left = nullptr;
            t[i]->right = i + 1 < t.size() ? t[i + 1] : nullptr;
        }
        return;
    }
};
```