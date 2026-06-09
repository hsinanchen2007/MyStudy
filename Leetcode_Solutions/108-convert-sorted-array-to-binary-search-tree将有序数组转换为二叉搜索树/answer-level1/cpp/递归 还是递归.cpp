### 简介
把数组劈开一半 中间的值赋给父节点，左边右边怎么半？继续递归！知道半边只有一个 或者没有元素 就停下来～

任何问题 随时交流～

### 代码
```
class Solution {
public:
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    if (nums.size() == 0) {
      return NULL;
    }
    if (nums.size() == 1) {
      return new TreeNode(nums[0]);
    }

    int middle = nums.size() / 2;

    TreeNode *node = new TreeNode(nums[middle]);

    vector<int> vec_left(nums.begin(), nums.begin() + middle);
    node->left = sortedArrayToBST(vec_left);

    vector<int> vec_right(nums.begin() + middle + 1, nums.end());
    node->right = sortedArrayToBST(vec_right);

    return node;
  }
};
```
