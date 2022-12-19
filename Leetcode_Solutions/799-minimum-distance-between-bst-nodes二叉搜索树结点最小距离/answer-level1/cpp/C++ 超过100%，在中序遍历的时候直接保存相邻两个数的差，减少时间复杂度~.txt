```
class Solution {
public:
    int min_dif = 100;
    int temp1 = -100;
    int temp2 = -100;
    int minDiffInBST(TreeNode* root) {
        return inorder(root);
    }

    int inorder(TreeNode* r)
    {
        if(!r)
          return min_dif;
        if(r -> left)
            inorder(r -> left);
        temp1 = temp2;
        temp2 = r -> val;
        min_dif = min(min_dif, temp2 - temp1);
        if(r -> right)
            inorder(r -> right);
        return min_dif;
    }
};
```