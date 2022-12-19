### 解题思路
此处撰写解题思路

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
    TreeNode *build(vector<int>& preorder, vector<int>& inorder, int presta, int prefin, int insta, int infin)
    //后面4个int为当前树的前序遍历在preorder中的【起点】与【终点】，中序遍历在inorder中的【起点】与【终点】
    {
        if (presta > prefin||insta > infin)//当前树是空
        {
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[presta]);//由前序遍历，第一个元素为根节点
        if (presta == prefin||insta == infin)//树只有一个元素，返回
        {
            return root;
        }
        int r = 0;//在中序遍历中找到根的位置
        for (int i = insta; i <= infin; i++)
        {
            if (inorder[i] == root->val)
            {
                r = i;
                break;
            }
        }
        //把中序遍历分为左子树的中序与右子树的中序，分别计算长度
        int llen = r - insta;
        int rlen = infin - r;
        //分别递归生成左子树与右子树；根据中序遍历的长度，计算前序遍历的起点终点在preorder中的位置
        root->left = build(preorder, inorder, presta + 1, presta + llen, insta, r - 1);
        root->right = build(preorder, inorder, presta + llen + 1, presta + llen + rlen, r + 1, infin);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, preorder.size() - 1, 0 , preorder.size() - 1);
    }
};
```