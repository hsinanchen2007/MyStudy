脑子里面第一反应想到的题解，速度很慢，只击败5%左右的C++解法，先写在这里做个记录，以后再回来看。
```
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return constructTree(nums, 0, nums.size());
    }
    TreeNode* constructTree(vector<int> nums, int left, int right){     // 构建时，右指针始终指向最后一个元素的下一位
        if(left>=right)
            return NULL;
        int mid = (left+right)/2;
        int val = nums[mid];
        TreeNode* root = new TreeNode(val);
        root->left = constructTree(nums, left, mid);
        root->right = constructTree(nums, mid+1, right);
        return root;
    }
};
```
