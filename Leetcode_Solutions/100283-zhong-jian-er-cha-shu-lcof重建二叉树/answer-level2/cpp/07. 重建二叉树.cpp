### 执行结果
执行用时: 16ms,在所有 C++ 提交中击败了90.97%的用户
内存消耗: 22.7MB,在所有 C++ 提交中击败了100.00%的用户

### 代码 & 注解

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
    /* 
        pre_start: 前序遍历的第一个数字
        in_start: 中序遍历的第一个数字
        size: 数组长度
    */
    TreeNode* RealBuild(vector<int>& preorder,vector<int>& inorder,int pre_start,int in_start,int size){
        if(size == 0)   return NULL;

        TreeNode* root = new TreeNode(preorder[pre_start]);
        if(size == 1)   return root;

        int i = 0; // 通过前序遍历，找到中序遍历中根节点的位置，从而划分左右子树
        while(inorder[in_start+i]!=preorder[pre_start])
            i++;
        root->left = RealBuild(preorder,inorder,pre_start+1,in_start,i);
        root->right = RealBuild(preorder,inorder,pre_start+i+1,in_start+i+1,size-1-i);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            TreeNode* root = RealBuild(preorder,inorder,0,0,preorder.size());
            return root;
    }
};
```