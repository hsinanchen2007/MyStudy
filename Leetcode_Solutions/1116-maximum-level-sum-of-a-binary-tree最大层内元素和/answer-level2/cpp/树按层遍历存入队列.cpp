```
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> qu;
        if(root!=0)
            qu.push(root);
        int level=0;
        int maxLevel = 1;
        int maxSum = root->val;
        while(!qu.empty())
        {
            int size = qu.size();
            int sum=0;
            for(int i=0;i<size;i++)
            {
                TreeNode *cur = qu.front();
                sum+=cur->val;
                qu.pop();
                if(cur->left!=NULL)
                {
                    qu.push(cur->left);
                }
                 if(cur->right!=NULL)
                {
                    qu.push(cur->right);
                }
            }
            level+=1;
            maxLevel = sum>maxSum ? level :maxLevel;
            maxSum = sum>maxSum ? sum : maxSum;
        }
        return maxLevel;
    }
};
```
