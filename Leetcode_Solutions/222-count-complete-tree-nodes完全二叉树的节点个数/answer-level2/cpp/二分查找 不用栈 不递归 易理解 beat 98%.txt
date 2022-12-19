```
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(NULL == root) return 0;
        TreeNode* node = root;
        int h = 0;
        while(node){
            h++;
            node = node->left;
        }
        
        node    = root;
        int sum = 1 << (h - 1);
        while((--h) > 0){
            TreeNode* right = node->right;
            if(judge(right, h)){
                sum += 1 << (h - 1);
                node = node->right;
            }else{
                node = node->left;
            }
        };
        return sum;
    }
    
    bool judge(TreeNode* node, int h){
        while(node){
            h--;
            node = node->left;
        }
        return h == 0;
    }
};
```
时间复杂度O(log(n)^2)
