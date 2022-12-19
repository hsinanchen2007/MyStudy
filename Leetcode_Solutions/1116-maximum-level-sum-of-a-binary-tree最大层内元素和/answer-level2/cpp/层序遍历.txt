
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
    int maxLevelSum(TreeNode* root) {
        int ans=0;//记录最大和的层号
        int sum=INT_MIN;//记录层内最大和
        int index=1;//记录层号

        queue<TreeNode*> help;
        help.push(root);
        //层序遍历
        while(!help.empty())
        {
            int n=help.size();
            int temp=0;
            for(int i=0;i<n;i++)
            {
                TreeNode* head=help.front();
                temp+=head->val;
                if(head->left) help.push(head->left);
                if(head->right) help.push(head->right);
                help.pop();
            }
            if(temp>sum)
            {
                sum=temp;
                ans=index;
            }
            index++;
        }

        return ans;
    }
};
```