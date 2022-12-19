### 解题思路
注意NULL点的判断，且叶子节点是在末端的，故只有左/右孩子的结点的情况需要另做遍历。

### 代码

```cpp
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left==NULL && root->right==NULL)  return 1;
        else if(root->left==NULL && root->right!=NULL) return 1 + minDepth(root->right);
        else if(root->left!=NULL && root->right==NULL) return 1 + minDepth(root->left);
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};
```