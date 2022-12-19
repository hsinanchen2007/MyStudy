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
    queue<TreeNode*> q;
    vector<vector<int>> res;

    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if(!root) return res;
        q.push(root);
        BFS(0);
        return res;
    }

    void BFS(int level)
    {
        vector<TreeNode*> TreeLever;
        vector<int> temp;

        while(!q.empty())
        {
            TreeLever.push_back(q.front());
            temp.push_back(q.front()->val);
            q.pop();
        }

        if(!TreeLever.empty())
        {
            res.push_back(temp);

            for(TreeNode* node:TreeLever)
            {
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            BFS(level+1);
        }  
    }
};
```
![image.png](https://pic.leetcode-cn.com/14b3d490839d2cd1ba1b930fdd19ad0b5ddc5399f9905cafc8efaaf649240918-image.png)
