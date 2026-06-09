#### 解题思路
![TIM图片20200405112344.png](https://pic.leetcode-cn.com/66e0e167ad625911313edb38857f154273a53fb6c33265a867931f1f870ff4a6-TIM%E5%9B%BE%E7%89%8720200405112344.png)
依次从左子树和右子树中获取第二大的值，然后取两者较小的一个，那么必定是第二大的值（根节点一定是最小的嘛）

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
    int findSecondMinimumValue(TreeNode* root) {
        if (root==NULL) return -1;
        if (root->left==NULL && root->right==NULL) return -1;
        int leftval = root->left->val;
        int rightval = root->right->val;
        if (leftval==root->val) leftval = findSecondMinimumValue(root->left);
        if (rightval==root->val) rightval = findSecondMinimumValue(root->right);
        if (leftval!=-1 && rightval!=-1) return min(leftval, rightval);
        if (leftval!=-1) return leftval;
        return rightval;
    }
};
```