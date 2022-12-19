### 解题思路
a1,b1表示前序遍历的首末位置
a2,b2表示中序遍历的首末位置
##用new初始化
##用while语句找到根节点所在位置

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
        //返回指向树节点的指针
        if (preorder.size()==0||inorder.size()==0) return NULL;
       
        return build(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);}
//a1,b1表示preoder的起始和终止，a2,b2表示inorder的起始和终止！！！
        TreeNode* build(vector<int>& preorder,vector<int>& inorder,int a1,int b1,int a2,int b2)
        {
            TreeNode* root=new TreeNode(preorder[a1]);//初始化    
            int i=a2;
            while(inorder[i]!=preorder[a1]) i++;

            int left=i-a2;//！！！！！！！！！！用inorder数组来划分长度
            int right=b2-i;
            if(left>0) root->left=build(preorder,inorder,a1+1,a1+left,a2,i-1);
            if(right>0) root->right=build(preorder,inorder,a1+left+1,b1,i+1,b2);

        return root;
        }
    
};
```