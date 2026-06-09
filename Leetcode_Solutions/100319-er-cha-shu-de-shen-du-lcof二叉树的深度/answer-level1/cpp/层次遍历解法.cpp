### 解题思路
此处撰写解题思路

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
    int maxDepth(TreeNode* root) {
        if(!root)return 0;
        queue<TreeNode *> nodeQ;
        nodeQ.push(root);
        int height = 0;
        while(!nodeQ.empty())
        {
            //存在层，高度+1
            height += 1;
            //对当前层操作
            int lenQ = nodeQ.size();
            while(lenQ--)
            {
                TreeNode *front = nodeQ.front();
                nodeQ.pop();
                if(front->left)nodeQ.push(front->left);
                if(front->right)nodeQ.push(front->right);
            }
        }
        return height;
    }
};
```