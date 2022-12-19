### 解题思路
递归
辅助栈迭代

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
 //递归解法
class Solution {
public:
    void helper(TreeNode* root , vector<int>& result){
        if(root == NULL)return;
        helper(root->left,result);
        result.push_back(root->val);
        helper(root->right,result);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        helper(root , result);
        return result;
    }
};
//辅助栈迭代解法
    /*vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> S;
        if(root == NULL)return result;
        TreeNode* x = root;
        while(1){
            if(x){
                S.push(x);//push在这里只有一个辣，因为遍历的原因只要把xpush就好了
                x = x->left;
            }
            else if(!S.empty()){
                x = S.top();S.pop();
                result.push_back(x->val);
                x = x->right;
            }
            else break;
        }
        return result;
    }
};*/
```