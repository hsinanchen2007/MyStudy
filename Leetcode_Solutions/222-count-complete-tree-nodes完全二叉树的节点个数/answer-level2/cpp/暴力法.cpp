
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
    int countNodes(TreeNode* root) {
        int ans=0;//记录结果

        if(root==NULL) return ans;

        queue<TreeNode*> help;
        help.push(root);
        //层序遍历
        while(!help.empty())
        {
            int n=help.size();//每一层节点数
            ans+=n;
            for(int i=0;i<n;i++)
            {
                TreeNode* head=help.front();
                if(head->left) help.push(head->left);
                if(head->right) help.push(head->right);
                help.pop();
            }
        }

        return ans;
    }
};
```