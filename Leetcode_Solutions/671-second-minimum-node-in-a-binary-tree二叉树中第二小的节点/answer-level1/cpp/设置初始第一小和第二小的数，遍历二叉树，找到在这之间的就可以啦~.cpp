```
class Solution {
public:
    long secondmin = 2147483648;
    int temp;
    int firstmin;
    int findSecondMinimumValue(TreeNode* root) {
       if(!root)
           return -1;
        firstmin = root -> val;
        return select(root);
            
    }
    
    int select(TreeNode* root)
    {
         if(!root)
            return secondmin;
       
        if(root -> val > firstmin && root -> val < secondmin)
            secondmin = root -> val;
        select(root -> left);
        select(root -> right);
        return secondmin == 2147483648 ? -1 : secondmin;
    }
};
```