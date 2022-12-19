数组有序，构造平衡二叉树，每个节点的位置与数组之间有明确的对应关系。
```
class Solution {
private:
    void Dfs(TreeNode* &node, int begin, int len, vector<int>& nums)
    {
        if (len <= 0) {
            return;
        }
        int idx = begin + len / 2;
        node = new TreeNode(nums[idx]);
        Dfs(node->left, begin, len/2, nums);
        Dfs(node->right, begin+len/2+1, (len-1)/2, nums);
    }    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = nullptr;
        Dfs(root, 0, nums.size(), nums);
        return root;
    }
};
```
