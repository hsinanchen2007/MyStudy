### 解题思路
我感觉我已经领悟到了解决二叉树类型题目方的关键：
1.框架，二叉树肯定有左右递归，结合第二点后再思考怎样递归，也就是考虑使用前中后序哪个遍历方法
2.最重要的：考虑当我们遍历到一个节点时希望该节点做什么，因为考虑当前节点也就是考虑所有节点（共性），其他节点的的作用是一样的。
3.考虑终止条件，再根据第二点看看该返回什么

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
    TreeNode* mirrorTree(TreeNode* root) {
        if(root==NULL) return root;          //3.终止条件
        TreeNode *p=mirrorTree(root->left);  //1.肯定是左右递归，然后考虑到第二点选择后序遍历
        TreeNode *q=mirrorTree(root->right);
        root->left=q;                        //2.该节点需要做的是：将两个子节点交换
        root->right=p; 
        return root;                         //3.考虑到第二点，应该返回当前节点的指针。
    }
};
```