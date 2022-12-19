### 解题思路
看了别人写的代码写的。思路很清晰

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
        if(preorder.size()==0||inorder.size()==0) return NULL;
        else return build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
        
    }
    TreeNode* build(vector<int>& preorder,int ps,int pe,vector<int>& inorder,int is,int ie){
        // 对ps进行处理
        TreeNode* root = new TreeNode(preorder[ps]);
        root->left=NULL;
        root->right = NULL;
        // 寻找ps元素在中序遍历中的位置。
        int i=is;
        while(i<=ie&&inorder[i]!=preorder[ps]){
            i++;
        } // 跳出循环时，恰好是中序遍历中的位置。
        int lenl = i - is;
        int lenr = ie - i;
        if(lenl>0){
            root->left  = build(preorder,ps+1,ps+lenl,inorder,i-lenl,i-1);
        }
        if(lenr>0){
            root->right = build(preorder,ps+lenl+1,pe,inorder,i+1,ie);
        }
        return root;
    }

};
```