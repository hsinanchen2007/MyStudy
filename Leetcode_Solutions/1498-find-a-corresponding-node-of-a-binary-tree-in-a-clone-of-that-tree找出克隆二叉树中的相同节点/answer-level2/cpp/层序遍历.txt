### 解题思路
都写递归，我写个层序遍历吧

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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*> ori,clo;
        ori.push(original);
        clo.push(cloned);
        while (!ori.empty() && !clo.empty())
        {
            if(ori.front() == target) return clo.front();
            else
            {
                if(ori.front()->left) 
                {
                    ori.push(ori.front()->left);
                    clo.push(clo.front()->left);
                }
                if(ori.front()->right) 
                {
                    ori.push(ori.front()->right);
                    clo.push(clo.front()->right);
                }
                ori.pop();
                clo.pop();
            }
        }
        return NULL;
    }
};
```