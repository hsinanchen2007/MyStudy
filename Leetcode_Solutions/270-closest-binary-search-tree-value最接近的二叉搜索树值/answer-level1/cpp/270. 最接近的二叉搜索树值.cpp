和二叉树值搜索一样思路
```
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        if(!root) return NULL;
        int res = root->val, curLen = 0;
        queue<TreeNode *> myQue;
        myQue.push(root);
        while(!myQue.empty()){
            curLen = myQue.size();
            while(curLen--){
                TreeNode *Node = myQue.front();
                myQue.pop();
                res = abs(res-target) < abs(Node->val-target) ? res : Node->val;
                if(Node->left != NULL && target < Node->val) myQue.push(Node->left);
                if(Node->right != NULL && target > Node->val) myQue.push(Node->right);
            }
        }
        return res;
    }
};
```

