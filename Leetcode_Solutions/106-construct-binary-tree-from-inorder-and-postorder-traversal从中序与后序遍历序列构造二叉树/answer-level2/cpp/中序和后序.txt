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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int pos = postorder.size()-1;
        return buildTree(postorder,pos,inorder,0,inorder.size()-1);
    }
    TreeNode* buildTree(vector<int>& postorder,int& pos,vector<int>&inorder,int left,int right){
        if(pos<0)return NULL;
        int i=left;
        for(i=left;i<=right;i++){
            if(inorder[i]==postorder[pos])
                break;
        }
        TreeNode* node = new TreeNode(postorder[pos]);
        if(right >= i+1){//必须先到右子树，因为--pos，先到右子树，再到左子树
            node->right=buildTree(postorder,--pos,inorder,i+1,right);
        }
        if(left<=i-1){
            node->left=buildTree(postorder,--pos,inorder,left,i-1);
        }
                
        return node;
    }
};
```