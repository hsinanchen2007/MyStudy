### 解题思路

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
class Solution 
{
public:
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(!root) return NULL;

        //查找key
        if(key<root->val)
        {
            root->left=deleteNode(root->left,key);  
            return root;
        }
        if(key>root->val)
        {
            root->right=deleteNode(root->right,key);
            return root;
        }

        //查找成功,root为待删结点
        if(!root->left && !root->right)  return NULL; //1.没有左或右结点
        if(!root->left && root->right) return root->right; //2.只有右结点
        if(root->left && !root->right) return root->left; //3.只有左结点

        root->val=FindMaxVal(root->left);  //4.有左和右结点,值更改为替换值
        root->left=deleteNode(root->left,root->val);  //删除用来替换待删结点的结点
        return root;  //返回 值更新为替换值的结点
    }

    //找左子数中的最大值(用来替换待删结点的值)
    int FindMaxVal(TreeNode* root)
    {
        while(root->right) root=root->right;
        return root->val;
    }
};
```