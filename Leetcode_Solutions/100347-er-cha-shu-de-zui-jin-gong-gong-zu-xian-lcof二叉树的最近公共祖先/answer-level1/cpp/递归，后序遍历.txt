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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)return nullptr;  //root为空，说明没找到
        if(root == p || root == q)return root;  //p或q自身为根节点，递归基！！！
        //下面相当于后序遍历
        TreeNode *leftNode = lowestCommonAncestor(root->left, p, q);  //访问左子树，找左子树的公共祖先
        TreeNode *rightNode = lowestCommonAncestor(root->right, p, q);  //访问右子树，找右子树的公共祖先
        if(!leftNode)return rightNode;  //左子树公共祖先为空，则一定在右子树
        if(!rightNode)return leftNode;  //右子树公共祖先为空，则一定在左子树
        return root;  //leftNode和rightNode都非空，说明左右子树都找到了公共祖先。p和q在root处分道扬镳，那root为公共祖先
    }
};
```