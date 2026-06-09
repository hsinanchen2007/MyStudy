### 解题思路
采用递归的思想
- 先构造根节点，根节点是先序遍历的第一个节点
- 寻找根节点在中序序列中的位置
- 递归构建根节点的左右子树

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
        if(preorder.size()==0||inorder.size()==0)
            return NULL;
        return build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
    TreeNode* build(vector<int>& preorder,int ps,int pe,vector<int>& inorder,int is,int ie){
        //构建根节点
        TreeNode* root=new TreeNode(preorder[ps]);
        root->left=NULL;
        root->right=NULL;
        
        //在中序序列中寻找根节点
        int i=is;
        while(i<=ie&&preorder[ps]!=inorder[i])
            ++i;
        //i指向中序序列中根节点的位置
        int ll=i-is;//左子树的序列长度
        int rl=ie-i;//右子树的序列长度
        
        //构建左右子树        
        if(ll>0){
            root->left=build(preorder,ps+1,ps+ll,inorder,is,is+ll-1);
        }
        if(rl>0){
            root->right=build(preorder,ps+ll+1,pe,inorder,is+ll+1,ie);
        }
        return root;
        
    }
};
```
### 优化
用map存储中序遍历序列，加速在中序序列中查找根节点的过程
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
        if(preorder.size()==0||inorder.size()==0)
            return NULL;
        //构建中序序列节点和位置的映射
        map<int,int> m;
        for(int i=0;i<inorder.size();++i){
            m[inorder[i]]=i;
        }
        return build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,m);
    }
    TreeNode* build(vector<int>& preorder,int ps,int pe,vector<int>& inorder,int is,int ie,map<int,int> m){
        //构建根节点
        TreeNode* root=new TreeNode(preorder[ps]);
        root->left=NULL;
        root->right=NULL;
        
        //在中序序列中寻找根节点
        int i=m[preorder[ps]];
        
        //i指向中序序列中根节点的位置
        int ll=i-is;//左子树的序列长度
        int rl=ie-i;//右子树的序列长度
        
        //构建左右子树        
        if(ll>0){
            root->left=build(preorder,ps+1,ps+ll,inorder,is,is+ll-1,m);
        }
        if(rl>0){
            root->right=build(preorder,ps+ll+1,pe,inorder,is+ll+1,ie,m);
        }
        return root;
        
    }
};
```
