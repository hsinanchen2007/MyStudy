### 解题思路
平衡二叉树的定义，左右子树的高度相差不为1，正常递归思路即可

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
        //平衡二叉树的定义，左右子树的高度相差不为1
        if (!root) return true;     
        int high = 0;
        return generate(root,high);
    }
private:
    bool generate(TreeNode* curTreeNode,int& high){
        
        int left_high  = 0;
        int right_high = 0;
        if (curTreeNode->left&&!generate(curTreeNode->left, left_high))return false;
        if (curTreeNode->right&&!generate(curTreeNode->right, right_high))return false;
        
        if (abs(left_high-right_high)>1) return false;
        
        high = max(left_high, right_high) + 1;
        return true;
    }
};
```