### 解题思路
为了节省空间，加快效率，将用于查找的map申明为public属性。
进一步理解，因为每次获取node的val都是靠前序遍历的第一个元素，而中序遍历的作用在于确定左右子树的边界。所以把前序遍历存为public属性，而中序遍历不用存。
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
    unordered_map<int,int> m;
    vector<int> tmpPreorder;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty())
            return NULL;
        tmpPreorder = preorder;
        for(int i=0;i<inorder.size();i++)
        {
            m.insert(make_pair(inorder[i],i));
        }
        return buildSonTree(0,0,inorder.size()-1);
    }
    TreeNode* buildSonTree(int preroot,int left_in, int right_in)
    {
        if(left_in>right_in)
            return NULL;
        TreeNode *root = new TreeNode(tmpPreorder[preroot]);
        int i = m[tmpPreorder[preroot]];
        root->left = buildSonTree(preroot+1,left_in,i-1);
        root->right = buildSonTree(preroot+(i-1-left_in+1)+1,i+1,right_in);
        return root;
    }

 
};
```