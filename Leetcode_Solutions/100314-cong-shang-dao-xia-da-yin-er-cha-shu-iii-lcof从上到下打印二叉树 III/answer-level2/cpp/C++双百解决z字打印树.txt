### 解题思路
按照II的方法打印。定义flag=true正向打印，flag=false时，反向打印，将r倒序输出即可。

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
        vector<vector<int>> a;
        if(root==nullptr) return a;
        queue<TreeNode*> que;
        que.push(root);
        int i=1;
        bool flag=true;
        while(que.size()!=0)
        {
            vector<int> r;//记录一层
            int l=que.size();//此层长度
            for(int i=0;i<l;i++)
            {      
                TreeNode* node=que.front();
                que.pop();
                r.push_back(node->val);
                if(node->left!=nullptr) que.push(node->left);
                if(node->right!=nullptr) que.push(node->right);
            }
            
            if(flag==true) a.push_back(r);
            else a.push_back(vector<int>(r.rbegin(),r.rend()));
            flag=!flag;
        }
        return a;

    }
};
```