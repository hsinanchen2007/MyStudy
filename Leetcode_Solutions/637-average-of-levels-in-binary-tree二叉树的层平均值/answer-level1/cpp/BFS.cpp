### 解题思路
外循环用于遍历层节点，即循环一次遍历一层；
内循环用于遍历一层内的每个节点；

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ret;
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty())
        {
            int len=qu.size();
            double sum=0;
            for(int i=0;i<len;i++)
            {
                root=qu.front();
                qu.pop();
                sum+=root->val;
                if(root->left!=NULL) qu.push(root->left);
                if(root->right!=NULL) qu.push(root->right);
            }
            ret.push_back(sum/len);
        }
        return ret;
    }
};
```