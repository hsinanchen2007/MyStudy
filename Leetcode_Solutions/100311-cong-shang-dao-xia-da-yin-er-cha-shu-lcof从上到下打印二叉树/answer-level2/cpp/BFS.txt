```
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> res;
        if(root == nullptr) return res;   //判断根节点是否为空
        
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            TreeNode* curNode = que.front(); que.pop();
            res.push_back(curNode->val);
            if(curNode->left) que.push(curNode->left);
            if(curNode->right) que.push(curNode->right);
        }
        
        return res;
    }
};
```
