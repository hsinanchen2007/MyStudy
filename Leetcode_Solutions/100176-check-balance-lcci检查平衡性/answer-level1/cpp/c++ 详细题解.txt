### 解题思路
depth函数用于计算以root为根节点的树的最大高度；
在isBalanced函数中，先判断根节点root的左右子树高度差是否小于2，再以root的左孩子右孩子为根节点递归

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
    int depth(TreeNode* root)//计算以root为根节点的子树的最大深度
    {
        if(root==NULL)  return 0;
        int left=depth(root->left);
        int right=depth(root->right);
        
        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)  return true;
        
        if(abs(depth(root->left) - depth(root->right)) < 2)//如果根节点的左右子树高度差小于2
            return isBalanced(root->left) && isBalanced(root->right);//继续递归判断左孩子右孩子
        return false;
    }
};
```
优化上述代码，在isBalanced函数中，判断条件可以直接用&&连接。
优化后，效率提升了不少
![1.png](https://pic.leetcode-cn.com/a96ba08a8854b0d54246d6ba2544575e5a4cbf3416e24a197d099dff7cf19539-1.png)

```
class Solution {
public:
    int depth(TreeNode* root)//计算以root为根节点的子树的最大深度
    {
        if(root==NULL)  return 0;
        int left=depth(root->left);
        int right=depth(root->right);
        
        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)  return true;
        
        return abs(depth(root->left)-depth(root->right))<2 && isBalanced(root->left)
            && isBalanced(root->right);
    }
};
```
如果感到有帮助，欢迎点赞或评论😄