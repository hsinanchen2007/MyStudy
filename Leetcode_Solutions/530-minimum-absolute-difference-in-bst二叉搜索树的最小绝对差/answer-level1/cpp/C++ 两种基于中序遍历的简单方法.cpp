# 方法一：常规思路，先中序遍历，再逐个比较

```c++ []
void Inorder(TreeNode* root, vector<int>& ivec) {
    if (root) {
        Inorder(root->left, ivec);
        ivec.push_back(root->val);
        Inorder(root->right, ivec);
    }
}
int getMinimumDifference(TreeNode* root) {
    vector<int> inorder;
    Inorder(root, inorder);//中序遍历
    int ans = INT_MAX;
    for (int i = 1; i < inorder.size(); i++)
        ans = abs(inorder[i - 1] - inorder[i]) < ans ? abs(inorder[i - 1] - inorder[i]) : ans;
    return ans;
}
```

# 方法二：优化思路，中序遍历的同时逐个比较

```c++ []
vector<int>ivec;
int ans = INT_MAX;
int getMinimumDifference(TreeNode* root) {
    if (!root) {
        ans = min(ans,getMinimumDifference(root->left));
        ivec.push_back(root->val);
        ans = min(ans, abs(ivec[ivec.size() - 1] - ivec[ivec.size()]));
        ans = min(ans,getMinimumDifference(root->right));
    }
    return ans;
}
```

方法一很直观简单，在熟练理解方法一的基础上，便可自然地优化为方法二，来避免过程中的遍历冗余问题。
