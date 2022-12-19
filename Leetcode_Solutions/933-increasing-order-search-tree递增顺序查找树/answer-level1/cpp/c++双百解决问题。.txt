### 解题思路
中序遍历一棵树，将值压入队列。
然后遍历队列，建立树。
返回树。
![image.png](https://pic.leetcode-cn.com/777faea0a24c8016462abfa01614fb7b5c402f771d29e5849b1f2f661614ebf0-image.png)

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
    queue<int> que;
    void f(TreeNode* root)
    {
        if(root!=NULL)
        {
            f(root->left);
            que.push(root->val);
            f(root->right);
        }
    }
    TreeNode* increasingBST(TreeNode* root) {
        f(root);
        TreeNode* newtree=new TreeNode(0),*tree=newtree;
        while(!que.empty())
        {
            TreeNode* p=new TreeNode(0);
            newtree->right=p;
            newtree->right->val=que.front();
            newtree=p;
            que.pop();
        }
        return tree->right;
    }
};
```