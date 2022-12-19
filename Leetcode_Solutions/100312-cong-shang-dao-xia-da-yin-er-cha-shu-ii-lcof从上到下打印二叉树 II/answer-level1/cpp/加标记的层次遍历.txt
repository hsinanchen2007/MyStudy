### 解题思路
这题和上题差不多，加一个last表示队列尾，当指针走到last说明一层就走完了。难度来说这个题应该是中等，上个题是简单。（代码在遍历略有不同，上题判断当前节点，本题判断左右孩子，左右孩子是通用方法）
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
        queue<TreeNode*> q;
        q.push(root);
        vector< vector<int> > res;
        TreeNode* last=root;
        vector<int> temp;
        if(root==NULL) return res;
        while(!q.empty())
        {
            TreeNode* p=q.front();
            q.pop();
            temp.push_back(p->val);
            if(p->left!=NULL)
            {
            q.push(p->left);
            }
            if(p->right!=NULL)
            {
            q.push(p->right);
            }
            if(p==last)
            {
                if(temp.size()!=0)
                res.push_back(temp);
                temp.clear();
                last=q.back();
            }
        }
        return res;
    }
};
```