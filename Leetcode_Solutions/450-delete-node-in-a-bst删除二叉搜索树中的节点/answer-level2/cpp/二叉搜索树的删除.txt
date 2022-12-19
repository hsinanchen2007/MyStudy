### 解题思路
解释都在注释中了
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
//  这个函数负责获取子树的最小节点 也就是最左边的节点了。
    TreeNode* getmin(TreeNode *root)
    {
        while(root->left!=NULL) root=root->left;
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;    
        //找到了就开始删除了
        if(root->val==key)
        {       //如果当前节点为叶子节点，直接返回null了
            if(root->left==NULL&&root->right==NULL) return NULL;
            else if(root->left==NULL)   return root->right;//如果左空右非空，返回右
            else if(root->right==NULL)  return root->left;  //如果左非空右空，返回左
        else{//左右都非空，则找到右边子树最小的那个节点(就是最左边的了)，然后交换其与root的值，再转而去删除右边子树最小的那个节点。
                   TreeNode*minnode= getmin(root->right);   
                   root->val=minnode->val;
                   root->right=deleteNode(root->right,minnode->val);
            }
        } //大于根节点进入右子树
        else if(root->val<key) root->right=deleteNode(root->right,key);
        //小于根节点进入左子树
        else root->left=deleteNode(root->left,key);
        return root;
    }
};
```