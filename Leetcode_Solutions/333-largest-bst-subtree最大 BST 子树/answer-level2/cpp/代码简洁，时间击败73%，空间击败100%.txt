```
class Solution {
public:
    enum{
        LEFT,
        RIGHT,
    };
    bool traverse(TreeNode* node, int& min_val, int& max_val, int& num, int& result){
        bool res = true;
        num = 0;
        int left_num    = 0;
        int right_num   = 0;
        int left_max_val  = INT_MIN;
        int left_min_val  = INT_MAX;
        int right_max_val = INT_MIN;
        int right_min_val = INT_MAX;
        if(node->left){
            if(!traverse(node->left, left_min_val, left_max_val, left_num, result) || node->val <= node->left->val || node->val <= left_max_val)
                res = false;
        }
        
        if(node->right){
            if(!traverse(node->right, right_min_val, right_max_val, right_num, result) || node->val >= node->right->val || node->val >= right_min_val)
                res = false;
        }
        if(!res)
            return false;
        
        num = left_num + right_num + 1;
        result = max(result, num);
        max_val = max(left_max_val, node->val);
        max_val = max(right_max_val, max_val);
        min_val = min(left_min_val, node->val);
        min_val = min(right_min_val, min_val);
        return true;
    }
    int largestBSTSubtree(TreeNode* root) {
        if(NULL == root) return 0;
        int min_value, max_value;
        int num = 0;
        int result = 0;
        traverse(root, min_value, max_value, num, result);
        return result;
    } 
};
```
