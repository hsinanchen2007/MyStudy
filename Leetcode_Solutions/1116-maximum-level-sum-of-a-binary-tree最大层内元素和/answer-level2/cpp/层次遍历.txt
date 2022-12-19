```
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        int level = 1,min_level = 1,mSum = 0;
        queue<TreeNode *> Q;
        Q.push(root);
        while(!Q.empty()){
            int size = Q.size();
            int sum = 0;
            for(int i = 0;i < size;i++){
                TreeNode *node = Q.front();
                Q.pop();
                if(node->left) Q.push(node->left);
                if(node->right) Q.push(node->right);
                sum += node->val;
            }
            if(sum > mSum){
                mSum = sum;
                min_level = level;
            }
            level++;
        }
        return min_level;
    }
};
```
