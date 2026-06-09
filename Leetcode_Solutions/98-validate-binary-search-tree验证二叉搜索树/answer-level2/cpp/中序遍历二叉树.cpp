### 解题思路
1.中序遍历一遍二叉树
2.如果是二叉搜索树那么它的节点值就应该是升序排列的，否则就不是二叉搜索树。

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
    bool isValidBST(TreeNode* root) {

        if(root == NULL)
        {
            return true;
        }
        inorder(root);//中序遍历一遍节点
        int size = result.size();

        //中序遍历以后的节点值应该是升序排列才行！
        for(int i = 1;i < size;i++)
        {
            if(result[i] <= result[i -1])//这里需要加上等号
            {
                return false;
            }
        }
        return true;
    }

    void inorder(TreeNode* root)
    {
        if(root == NULL)
        {
            return;
        }
        inorder(root->left);

        result.push_back(root->val);//中序
        
        inorder(root->right);

    }
    vector<int> result;//全局

};
```