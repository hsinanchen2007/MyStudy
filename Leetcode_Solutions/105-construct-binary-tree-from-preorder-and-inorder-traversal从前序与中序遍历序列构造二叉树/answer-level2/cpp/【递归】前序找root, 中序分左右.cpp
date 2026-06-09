### 解题思路

前序找root：
  第一个节点一定是整个的root节点
中序分左右：
  由于没有重复元素，在中序数组里find找到根节点的值，它左边的子数组一定是左子树in_left，右边的数组一定是右子树in_right。
  而前序遍历：先访问根节点，然后访问所有左子树的节点，最后访问右子树的节点。所以，根节点数组中根节点后长度为in_left.size()的数据即为前序左子树pre_left，紧接着的长度为in_right.size()的右子树为前序右子树pre_right。
  此时已经找到左子树的前序遍历pre_left和中序遍历in_left，右子树的前序遍历pre_right和中序遍历in_right，然后采用先序遍历创建整体的Tree即可

**题解的效率可能不高，胜在思路清楚，搞清楚问题后，可以不用新创建vector，用索引进行控制，时间和空间的效率会比较高**

### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      if (preorder.empty()) {
        return nullptr;
      }

      int root_val = preorder[0];
      auto it = find(inorder.begin(), inorder.end(), root_val);

      vector<int> in_left(inorder.begin(), it);
      vector<int> in_right(it + 1, inorder.end());

      auto begin_it = preorder.begin() + 1;
      vector<int> pre_left(begin_it, begin_it + in_left.size());
      begin_it = begin_it + in_left.size();
      vector<int> pre_right(begin_it, begin_it + in_right.size());

      TreeNode* root = new TreeNode(root_val);
      root->left = buildTree(pre_left, in_left);
      root->right = buildTree(pre_right, in_right);

      return root;
    }
};
```