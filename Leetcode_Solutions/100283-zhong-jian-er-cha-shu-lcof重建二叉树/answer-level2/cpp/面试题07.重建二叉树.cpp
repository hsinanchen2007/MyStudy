### 解题思路
核心思路：对左右子树递归调用建树函数，返回值分别赋给root的左右子节点指针
注意：为了便于快速查找根节点在中序遍历中的位置，预先准备一个hashmap存好中序遍历中数和index的键值对
执行用时 :12 ms, 在所有 C++ 提交中击败了96.99%的用户
内存消耗 :23.1 MB, 在所有 C++ 提交中击败了100.00%的用户
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
    unordered_map<int,int>umap;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(inorder.size()==0)return NULL;    
        for(int i=0;i<inorder.size();i++){
            umap[inorder[i]]=i;
        }
        TreeNode*root=build(preorder,inorder,0,0,inorder.size()-1);
        return root;
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int pos,int begin,int end){
        if(begin>end)return NULL;
        TreeNode*root=new TreeNode(preorder[pos]);
        int inpos=umap[preorder[pos]];
        root->left=build(preorder,inorder,pos+1,begin,inpos-1);
        root->right=build(preorder,inorder,pos+inpos-begin+1,inpos+1,end);
        return root;
    }
};
```