### 解题思路
参考《剑指offer》

前序遍历的第一个数字就是树的根节点的值，找到中序遍历中根节点，将左半部分划分为左子树，右半部分划分为由子树，进行递归操作。

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int lenPre = preorder.size();
        int lenIn = inorder.size();
        // 检查输入是否为空、是否合法
        if(preorder.empty() || inorder.empty() || lenIn != lenPre){
            return nullptr;
        }
        // 递归操作
        return construct(preorder, 0, lenPre - 1, inorder, 0, lenIn - 1);
    }

    TreeNode* construct(vector<int>& preorder, int startPre, int endPre, vector<int>& inorder, int startIn, int endIn){
        if(startPre > endPre){
            return nullptr;
        }
        // 先序遍历的第一个元素就是根节点的值
        TreeNode* root = new TreeNode(preorder[startPre]);    // 初始化根节点

        // 在中序遍历序列中找到根节点的值
        int leftTree = 0; // leftTree代表左子树的长度 - 1(除去根节点))
        while(inorder[startIn + leftTree] != preorder[startPre]){
            ++leftTree;
        }

        // 创建左子树
        // 在先序遍历序列中，左子树从startPre+1（除去跟节点）开始，到startPre + leftTree = (startPre + 1) + (leftTree - 1)
        // 在中序遍历中，左子树从startIn开始，到startIn + leftTree - 1
        root->left = construct(preorder, startPre + 1, startPre + leftTree, inorder, startIn, startIn + leftTree - 1);
        // 创建右子树
        // 在先序遍历中，右子树从startPre + leftTree + 1开始，到endPre结束
        // 在中序遍历中，右子树从startIn + leftTree + 1开始，到endIn结束
        root->right = construct(preorder, startPre + leftTree + 1, endPre, inorder, startIn + leftTree + 1, endIn);

        return root;

    }
};
```