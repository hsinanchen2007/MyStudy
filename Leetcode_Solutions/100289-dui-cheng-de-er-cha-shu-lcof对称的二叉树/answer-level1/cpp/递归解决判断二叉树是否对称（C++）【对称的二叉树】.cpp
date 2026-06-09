### 解题思路
- 递归解决，注意因为判断的时候，不能只是单单判断一个节点的左孩子和有孩子是否一样，再递归向下，这样是不行的，和翻转二叉树不一样！注意写题前先构思好方法！
- 本题用递归，每个节点应该分成两部分来判断。利用这个节点的左右孩子传入帮助函数。然后递归的边界条件判断后，记得是左孩子的右孩子和右孩子的左孩子进行比较，左孩子的左孩子和右孩子的右孩子进行比较，然后看是否都满足。这样才是判断是否是二叉树的思路！


**翻转二叉树时，每个节点的左右孩子翻转过来即可，但是判断是否对称时，这样的思路就不可以了！要考虑全面！分开两个数进行判断！**

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
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)  return true;
        else{
            return help(root->left,root->right);
        }
    }

    bool help(TreeNode *left,TreeNode *right){
        if(!left&&!right)  return true;
        if(left&&!right) return false;
        if(!left&&right) return false;
        if(left->val!=right->val)  return false;
        return help(left->left,right->right)&&help(left->right,right->left); //这里注意！！

    }
};
```