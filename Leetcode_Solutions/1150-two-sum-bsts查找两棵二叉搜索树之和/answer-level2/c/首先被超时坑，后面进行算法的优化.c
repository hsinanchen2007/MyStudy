```
//首先尝试这个代码，迭代次数过多，超时
bool twoSumBSTs(struct TreeNode* root1, struct TreeNode* root2, int target){
    if (!root1 || !root2)
        return false;
    else
    {
        if (root1->val + root2->val < target)
            return twoSumBSTs(root1, root2->right, target) || twoSumBSTs(root1->right, root2, target);
        else if (root1->val + root2->val > target)
            return twoSumBSTs(root1, root2->left, target) || twoSumBSTs(root1->left, root2, target);
        else
            return true;
    }
}
//然后进行修改
bool twoSumBSTs1(struct TreeNode* root1, int target){ 
    if (!root1)
        return false;
    else
    {
        if (root1->val < target)
            return twoSumBSTs1(root1->right, target);
        else if (root1->val > target)
            return twoSumBSTs1(root1->left, target);
        else
            return true;
    }
}

bool twoSumBSTs(struct TreeNode* root1, struct TreeNode* root2, int target){
    if (!root1 || !root2)
        return false;
    else
    {
        int left, right;
        left = twoSumBSTs(root1, root2->left, target);  // 向左向右移动
        right = twoSumBSTs(root1, root2->right, target);
        return twoSumBSTs1(root1, target - root2->val) || left || right;
    }
}
```
