```
class Solution {
public:
    int re = 0;
    void search(TreeNode*node,int &num){
        if(!node)return;
        if(node->left){
            search(node->left,num);
            re += abs(num);
            node->val += num;
        }
        if(node->right){
            search(node->right,num);
            re += abs(num);
            node->val += num;
        }
        num = node->val-1;
    }
    int distributeCoins(TreeNode* root) {
        int num = 0;
        search(root,num);
        return re;
    }
};
```
