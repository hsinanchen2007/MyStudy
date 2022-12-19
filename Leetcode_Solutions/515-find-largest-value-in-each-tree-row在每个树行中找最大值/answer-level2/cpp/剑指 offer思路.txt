### 解题思路
利用两个数值记录层数
找出最大值

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
        vector<int> result;
        if(root == NULL) return result;

        queue<TreeNode*> q;
        q.push(root);

        int thislevel=1;
        int nextlevel=0;
        int maxval = INT_MIN;

        while(q.size()){
            TreeNode* front = q.front();
            maxval = max(maxval, front->val);
            q.pop();
            thislevel--;

            if(front->left){
                q.push(front->left);
                nextlevel++;
            }
            if(front->right){
                q.push(front->right);
                nextlevel++;
            }
            if(thislevel == 0){
                result.push_back(maxval);
                maxval = INT_MIN;
                thislevel = nextlevel;
                nextlevel=0;
            }

        }
        return result;

    }
};
```