传不了图片，击败96%与100%

```
代码块
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty())
            return NULL;

        TreeNode* node = new TreeNode(1);//创建树节点
        node->val = nums[nums.size()/2];//给节点赋值，每次数组中值
        vector<int> leftarray(nums.begin(),nums.begin() + nums.size()/2);//分成左数组
        node->left = sortedArrayToBST(leftarray);//构建左子树
        vector<int> rightarray(nums.begin() + nums.size()/2+1, nums.end());//分成右数组
        node->right = sortedArrayToBST(rightarray);//构建右子树

        return node;
    }
};
```




