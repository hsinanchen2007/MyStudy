### 解题思路
每一层一个队列。详情看代码。
![image.png](https://pic.leetcode-cn.com/de5a22f65ff68dec71bc09f26602224a4f9a87bc300b0617d085187a8bcdbfeb-image.png)

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> answer;
        queue<TreeNode*> que1,que2;
        que1.push(root);
        vector<int> temp;
        while(!que1.empty())
        {
            TreeNode* top=que1.front();
            if(top->left) que2.push(top->left);
            if(top->right) que2.push(top->right);
            temp.push_back(top->val);
            que1.pop();
            if(que1.empty())
            {
                que1=que2;
                answer.push_back(temp);
                temp.clear();
                queue<TreeNode*> que;
                que2=que;
            }
        }
        return answer;
    }
};
```