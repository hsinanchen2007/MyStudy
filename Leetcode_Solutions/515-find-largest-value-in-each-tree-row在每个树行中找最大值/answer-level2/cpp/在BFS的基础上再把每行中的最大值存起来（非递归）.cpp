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
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
       vector<int> ans;                         //存储每行的最大值
        if(root == NULL)
         return ans;
        queue<TreeNode*>q;                      //存树每行的结点 
        q.push(root);
        
        while(!q.empty())
        {
            int max1 =INT_MIN;                   //选择开始比较的标准
            int size = q.size();
            for(int i=0;i<size;i++)              //遍历树中的一行
            {    
                 TreeNode* cur = q.front();
                 q.pop();
                 if(cur->left) q.push(cur->left);
                 if(cur->right) q.push(cur->right);
                 max1 = max(max1,cur->val);       //找出行中的最大值  
            }
            ans.push_back(max1);                     //把最大值存入结果数组中 
        }
        return ans;
    }
};
```