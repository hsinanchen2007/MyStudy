### 解题思路
学习官方递归解法
函数int hight(TreeNode* root)的过程
例[1,1,1]
1 + max(hight(左子), hight(右子))
1 + max(1 + max(hight(左子)，hight(右子))，1 + max(hight(左子), hight(右子)))
1 + max(1 + max(-1, -1), 1 + max(-1, -1))
1 + max(0, 0)
1   <-----即求出根节点高度


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
private:
    int hight(TreeNode* root)
    {
        if(root == NULL)
            return -1;
        else
            return 1 + max(hight(root->left), hight(root->right));
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        return (abs(hight(root->left) - hight(root->right)) <= 1) 
        && isBalanced(root->left)
        && isBalanced(root->right);
    }
};
```