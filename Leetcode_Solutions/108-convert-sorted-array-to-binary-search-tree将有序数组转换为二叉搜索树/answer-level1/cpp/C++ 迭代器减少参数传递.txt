C++ iterator, 左闭右开较简单

```c++
class Solution {
public:
    template <typename Iterator>
    TreeNode *createBST(Iterator begin, Iterator end) {
      if (begin == end)
        return nullptr;
      
      Iterator mid = std::next(begin, std::distance(begin, end) / 2);
      TreeNode *root = new TreeNode(*mid);

      root->left = createBST(begin, mid);
      root->right = createBST(std::next(mid, 1), end);
      return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
      return createBST(nums.cbegin(), nums.cend());
    }
};
```
