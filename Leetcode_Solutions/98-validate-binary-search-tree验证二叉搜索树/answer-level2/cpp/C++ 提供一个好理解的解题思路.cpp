先获取node左右两颗子树的数值区间，
node的数值需要大于左子树的最大值，小于右子树的最小值，满足这个性质即为BST

class Solution {
 public:
  bool isValidBST(TreeNode* root) {
    long min, max;
    return Valid(root, min, max);
  }

 private:
  bool Valid(TreeNode* node, long& ref_min, long& ref_max) {
   
    if (node == nullptr) {
      return true;
    }

    long lmin = LONG_MAX, lmax = LONG_MIN, rmin = LONG_MAX, rmax = LONG_MIN;
    TreeNode* left = node->left;
    TreeNode* right = node->right;
    int val = node->val;

    if (!Valid(left, lmin, lmax)) {
      return false;
    }
    if (lmax >= val) {
      return false;
    }

    if (!Valid(right, rmin, rmax)) {
      return false;
    }
    if (rmin <= val) {
      return false;
    }

    ref_min = std::min<long>(lmin, val);
    ref_max = std::max<long>(rmax, val);
    return true;
  }
};
```