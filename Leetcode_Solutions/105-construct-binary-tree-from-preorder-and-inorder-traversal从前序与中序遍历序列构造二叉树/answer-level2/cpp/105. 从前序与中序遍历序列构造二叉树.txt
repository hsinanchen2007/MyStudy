### 解题思路
真的好绕，调了半天。
核心思想：
1.从前序遍历中第一个元素是根 i，从中序遍历中找到根 j
1)中序遍历左侧（0~j-1）是左子树的中序遍历，中序遍历右侧（j~end）是右子树的中序遍历；
2)前序遍历根的下一个元素（i+1~i+1+左子树长度）是左子树的前序遍历，（i+1+左子树长度~end）是右子树的前序遍历

至此，左右子树的前序遍历和中序遍历都已经得到了，可以迭代构造二叉树。


### 代码

```cpp
class Solution {
public:
    TreeNode *dfs(vector<int> &preorder, int pstart, int pend, vector<int> &inorder, int istart, int iend)
    {
        if (pstart > pend || istart > iend) {
            return nullptr;
        }

        TreeNode *pnode = new TreeNode(preorder[pstart]);
        int i = 0;
        while (inorder[istart + i] != preorder[pstart]) {
            i++;
        }

        pnode->left = dfs(preorder, pstart + 1, pstart + i, inorder, istart, istart + i - 1);
        pnode->right = dfs(preorder, pstart + i + 1, pend, inorder, istart + i + 1, iend);


        return pnode;
    }


    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return dfs(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};
```