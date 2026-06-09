### 解题思路
通过先序遍历我们可以找到root的位置
通过root在中序遍历中的位置，我们分别可以找到左子树和右子树
### 代码

```cpp

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == NULL || inorder.size() == NULL)
            return NULL;
        return build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
    TreeNode* build(vector<int>& preorder,int p_s,int p_e,vector<int>& inorder,int i_s,int i_e){
        TreeNode* root = new TreeNode(preorder[p_s]);
        root->left = NULL;
        root->right = NULL;
        int i = i_s;
        // 在中序遍历中找根结点的位置
        while(i < i_e && preorder[p_s] != inorder[i])
            i++;
        // 计算左子树和右子树的长度
        int l_len = i - i_s;
        int r_len = i_e - i;
        // 如果左右子树存在，则通过在先序遍历和中序遍历中的位置分别构建左子树和右子树
        if(l_len > 0)
            root->left = build(preorder,p_s+1,p_s+l_len,inorder,i_s,i_s+l_len-1);
        if(r_len > 0)
            root->right = build(preorder,p_s+l_len+1,p_e,inorder,i_s+l_len+1,i_e);
        return root;
    }
};
```