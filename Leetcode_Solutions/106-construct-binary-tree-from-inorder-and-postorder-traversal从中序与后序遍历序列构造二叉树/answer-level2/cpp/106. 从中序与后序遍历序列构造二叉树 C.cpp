### 解题思路
类似题目：105. 从前序与中序遍历序列构造二叉树
主要还是用分治算法不断获得中序和后序的左右子树，然后依据后序来获得根节点

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
    TreeNode *dfs(vector<int> &inorder, int istart, int iend, vector<int> &postorder, int pstart, int pend)
    {
        if (pstart > pend || istart > iend) {
            return nullptr;
        }

        TreeNode *pnode = new TreeNode(postorder[pend]);
        int i = 0;
        while (postorder[pend] != inorder[istart + i]) {
            i++;
        }

        pnode->left = dfs(inorder, istart, istart + i - 1, postorder, pstart, pstart + i - 1);
        pnode->right = dfs(inorder, istart + i + 1, iend, postorder, pstart + i, pend - 1);

        return pnode;
    }


    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        return dfs(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};
```