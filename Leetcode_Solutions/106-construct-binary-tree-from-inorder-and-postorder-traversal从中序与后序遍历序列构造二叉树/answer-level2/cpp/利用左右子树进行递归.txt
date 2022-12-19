### 解题思路
- 易知后续遍历的最后一个值为根节点的值。
- 分离左、右子树的中序遍历数组：利用根节点的值在中序遍历数组中求出左子树的节点个数n（在根节点左边的为左子树节点，右边的为右子树节点）。
- 分离左、右子树的后续遍历数组：知道了左右子树各自节点个数又可以把后续遍历中左子树的节点分离出来（即前n个为左子树节点）。
- 根据分离出来的左子树的中序、后续遍历数组，右子树的中序、后续遍历数组递归即可。

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
        return buildTree(0,inorder.size()-1,0,postorder.size()-1,inorder,postorder);
    }
    TreeNode* buildTree(int ll,int lr,int rl,int rr,vector<int> inorder,vector<int> postorder){
        if(ll>lr||rl>rr) return NULL;
        int len=0;
        for(int i=ll;i<=lr;i++){
            if(inorder[i]==postorder[rr]) break;
            len++;
        }
        TreeNode* root=new TreeNode(postorder[rr]);
        root->left=buildTree(ll,ll+len-1,rl,rl+len-1,inorder,postorder);
        root->right=buildTree(ll+len+1,lr,rl+len,rr-1,inorder,postorder);
        return root;
    }
};
```