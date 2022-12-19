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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int k = q.size();
            ans = max(ans, k);
            list<TreeNode*> tempList;
            for(int i = 0 ; i < k ; ++i)
            {
                TreeNode* f = q.front();
                q.pop();
                if(f->left) tempList.push_back(f->left);
                else    tempList.push_back(new TreeNode(-INT_MAX));
                if(f->right) tempList.push_back(f->right);
                else    tempList.push_back(new TreeNode(-INT_MAX));
            }
            while(tempList.front() && tempList.front()->val == -INT_MAX)
                tempList.pop_front();
            while(tempList.back() && tempList.back()->val == -INT_MAX)
                tempList.pop_back();
            while(tempList.size() > 0)
            {
                auto node = tempList.front();
                //cout<<node->val<<endl;
                q.push(node);
                tempList.pop_front();
            }
        }
        return ans;
    }
private:
    int ans = 0;
};
```