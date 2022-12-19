### 解题思路
用栈记录除了root->val 之外的最小值。

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
private:
    stack<int>res;
public:
    int findSecondMinimumValue(TreeNode* root) {
        if(!root){
            return -1;
        }
        //根节点
        secondVal(root,root->val);
        if(res.empty()){
            return -1;
        }
        return res.top();
    }

    void secondVal(TreeNode *root,int val){
        if(!root){
            return;
        }

        if(val != root->val){
            if(res.empty()){
                res.push(root->val);
            }
            else{
                if(root->val < res.top()){
                    res.pop();
                    res.push(root->val);
                }
            }
        }

        secondVal(root->left, val);
        secondVal(root->right, val);
        return;
    }
};
```