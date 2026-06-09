```
class Solution {
public:
    int sum = 0;
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(!root)
            return sum;
        rangeSumBST(root -> left, L, R);
        sum += (root -> val >= L && root -> val <= R) ? root -> val : 0;
        //if(root -> val < R)
        rangeSumBST(root -> right, L, R);

        return sum;
    }
};
```