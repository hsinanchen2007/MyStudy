### 解题思路
1. 思路1，中序遍历判断后一个是否大于前一个
2. 思路2，基于边界的递归，边界使用long long 的（LLONG_MIN, LLONG_MAX）防止int 的溢出

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
    //方法2：基于边界的递归
    bool isValidBST(TreeNode* root){
        return isValidBSTCore(root, LLONG_MIN, LLONG_MAX);
    }
    bool isValidBSTCore(TreeNode* root, long long lower, long long upper){
        if(root==nullptr) return true;
        long long curVal = root->val;
        if(curVal<=lower || curVal>=upper)
            return false;
        return isValidBSTCore(root->left, lower, curVal) && isValidBSTCore(root->right, curVal, upper);
    }

    //方法1：中序遍历判断后一个是否大于前一个
    bool isValidBST1(TreeNode* root) {
        stack<pair<TreeNode*, bool>> mStack;
        mStack.push(make_pair(root, false));
        int preVal;
        bool isinit = false;
        while(!mStack.empty()){
            TreeNode* node = mStack.top().first;
            bool visit = mStack.top().second;
            mStack.pop();
            if(node==nullptr){
                continue;
            }
            else if(visit){
                if(!isinit){
                    preVal = node->val;
                    isinit = true;
                }
                else{
                    if(node->val<=preVal)
                        return false;
                    else
                        preVal = node->val;
                }
            }
            else{
                mStack.push(make_pair(node->right, false));
                mStack.push(make_pair(node, true));
                mStack.push(make_pair(node->left, false));
            }
        }
        return true;
    }
};
```