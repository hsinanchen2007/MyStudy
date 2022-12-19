### 解题思路
此处撰写解题思路
看到这个题的思路首先是想到用那种遍历方式遍历二叉树呢？因为路径的定义，我认为中序遍历比较合适，中序遍历是怎么做的呢？
```
void find(ListNode *root){
    if(!root) return;
    find(root->left);
    find(root->right);
}
```
接下来就是去分析这道题：
对于任意一个节点，有以下三种情况：
1、左节点的值+当前节点的值+右节点的值（左右节点的值如果<0，我们当然是不想加）
2、左节点的值+当前节点的值+当前节点父节点的值（没有则不加）
3、当前节点的值+右节点的值+当前节点父节点的值（没有则不加）
这三种情况中的最大值就是最大路径和，但是作为子问题的时候，要想还往上或者说继续遍历这棵树，我们当前的选择一定不能为第一种情况，也就是如果继续遍历，当前节点的暂时最大路径和应该是
当前节点的值+max(以左节点为根节点的暂时最大路径和,以右节点为根节点的暂时最大路径和)
因为每次返回的都是上面显示的那种形式，也就是说，以当前节点为根节点的树的最大路径，可以利用之前计算的子树的最大路径和。

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
    int maxPathSum(TreeNode* root) {
        //if(!root) return out;
        maxSum(root);
        return out;
    }
private:
    int out=INT_MIN;
    int maxSum(TreeNode* root) {
        if(!root) return 0;
        int left=max(maxSum(root->left), 0);
        int right=max(maxSum(root->right), 0);
        int tmp=root->val+left+right;
        out = max(out, tmp);
        return root->val+max(left, right);
    }
};
```