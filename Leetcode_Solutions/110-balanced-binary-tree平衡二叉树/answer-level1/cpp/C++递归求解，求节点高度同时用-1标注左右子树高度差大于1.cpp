### 解题思路
关键点1，要获取左右子树的高度，从而求差。差大于1，就要中断求差了，然后层层往上抛。
关键点2，如果发现不满足条件了，就要返回falsed。但是getLen除了要求节点高度，还要能够标注一个值用于外层函数返回false,因此就用-1.

### 代码

```cpp
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
    bool isBalanced(TreeNode* root) {
        return getLen(root) == -1 ? false:true;
    }
    int getLen(TreeNode* root)
    {
        if (root == NULL) return 0;
        int left = 1+getLen(root->left);
        int right = 1+getLen(root->right);
        if (left == 0 || right == 0) return -1;
        //注意用-1作为一个标记，只要左右字数高度差大于1，就返回-1，层层往上抛。
        return abs(left-right)>1 ? -1 : max(left,right);
    }
};
```