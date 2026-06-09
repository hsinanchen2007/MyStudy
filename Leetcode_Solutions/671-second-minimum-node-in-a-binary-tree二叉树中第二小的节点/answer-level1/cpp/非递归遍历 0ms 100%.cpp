### 解题思路
此处使用的是非递归层次遍历，设立left=最小值，遍历过程找到第一个比left大的值设为right，在遍历过程中及时更新right，使right是除了left的最小的数

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
    int findSecondMinimumValue(TreeNode* root) {
        queue<TreeNode*> que;
        if(!root)
            return -1;
        int left=root->val,right=left-1;
        que.push(root);
        while(!que.empty())
        {
            TreeNode* t=que.front();
            que.pop();
            if(right==left-1)
            {
                if(t->val>left)
                    right= t->val;
            }else{
                if(t->val>left&&t->val<right)
                    right=t->val;
            }
            if(t->left)
                que.push(t->left);
            if(t->right)
                que.push(t->right);
        }
        if(right!=left-1)
            return right;
        return -1;        
    }
};
```