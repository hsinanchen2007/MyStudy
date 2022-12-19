### 解题思路
pathSumHelper求解从node向下且包含node的符合条件的路径
pathSum遍历树中所有节点，对每个节点做一次pathSumHelper
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
    int pathSumHelper(TreeNode* node,int sum){
        if(node==nullptr) return 0;
        int res = pathSumHelper(node->left,sum-node->val)+pathSumHelper(node->right,sum-node->val);
        if(node->val==sum) res+=1;
        return res;
    }
public:
    int pathSum(TreeNode* root, int sum) {
        if(root==nullptr) return 0;
        queue<TreeNode*> myque;
        myque.push(root);
        int res =0;
        while(!myque.empty()){
            TreeNode* tmp = myque.front();
            res+=pathSumHelper(tmp,sum);
            myque.pop();
            if(tmp->left!=nullptr) myque.push(tmp->left);
            if(tmp->right!=nullptr) myque.push(tmp->right);
        }
        return res;
    }
};
```