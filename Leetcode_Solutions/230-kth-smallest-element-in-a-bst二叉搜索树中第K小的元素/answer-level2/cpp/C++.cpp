### 解题思路
此处撰写解题思路

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
    int kthSmallest(TreeNode* root, int k) {
        
        //中序遍历 递归
        vector<int> v;
        inorder(root, v);
        return v.at(k - 1);
    }

    void inorder(TreeNode* root, vector<int>& v)
    {
        if(root == nullptr)
            return;
        
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }


    //迭代
    int kthSmallest(TreeNode* root, int k) {
        
        stack<TreeNode*> s;
        TreeNode* cur = root;
        
        while(!s.empty() || cur)
        {
            if(cur) //当cur及其左子树全部入栈，直到为空
            {
                s.push(cur); 
                cur = cur->left;
            }
            else //cur为空且栈非空 出栈
            {
                TreeNode* node = s.top();
                s.pop();

                --k;
                if(k == 0)
                    return node->val;
                
                cur = node->right; //右子树
            }
        }
        return 0;
    }
};
```