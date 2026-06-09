```c++
class Solution {
public:

    bool isEqual(TreeNode* root, int &sum, int target){
        if(root==NULL)
            return false;
        sum += root->val;
        if(sum == target && root->left==NULL && root->right==NULL)
            return true;
        bool temp = isEqual(root->left,sum, target)^isEqual(root->right,sum, target);
        sum -= root->val;
        return temp;
    }

    bool hasPathSum(TreeNode* root, int sum) {
        int num = 0;
        return isEqual(root, num, sum);
    }
};
```
这个题思路很简单，递归一下解决就可以了，注意一下最后需要把sum恢复原状。