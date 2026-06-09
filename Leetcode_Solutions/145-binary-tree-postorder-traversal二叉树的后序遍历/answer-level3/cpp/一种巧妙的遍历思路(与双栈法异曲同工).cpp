- 先按照"根-右-左"的顺序遍历二叉树(和先序遍历有些像)，然后将遍历的结果反转过来就是“左-右-根”，也就是后序遍历了

```
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> nodeStack;
        TreeNode *cur = root;
        while(cur||!nodeStack.empty()){
            if(cur){
                nodeStack.push(cur);        //根
                res.push_back(cur->val);    //先序
                cur =cur->right;            //右
            }
            else{
                cur=nodeStack.top()->left;  //左
                nodeStack.pop();
            }
        }
        //反转遍历结果
        reverse(res.begin(),res.end());
        return res;
    }
};
```
