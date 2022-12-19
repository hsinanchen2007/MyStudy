### 解题思路
 */
1.find diatance用法
2.注意边界
            vector<int> rightPreorder(preorder.begin() + leftLength + 1, preorder.end());
            vector<int> rightInorder(inorder.begin() + leftLength + 1, inorder.end());
3.迭代器赋值 没有=的形式
            vector<int> rightPreorder(preorder.begin() + leftLength + 1, preorder.end());
            vector<int> rightInorder(inorder.begin() + leftLength + 1, inorder.end());     

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
        if (preorder.empty())
            return NULL;

        TreeNode* root = new TreeNode(preorder[0]);

        int mid = getVectorIndex(inorder, preorder[0]);
        int leftLength = mid;
        int rightLength = preorder.size() - 1 - leftLength;

        if (leftLength <= 0)
            root->left = NULL;
        else {
            vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + leftLength + 1);
            vector<int> leftInorder(inorder.begin(), inorder.begin() + leftLength);
            root->left = buildTree(leftPreorder, leftInorder);
        }

        if (rightLength <= 0 )
            root->right = NULL;
        else {
            vector<int> rightPreorder(preorder.begin() + leftLength + 1, preorder.end());
            vector<int> rightInorder(inorder.begin() + mid + 1, inorder.end());
            root->right = buildTree(rightPreorder, rightInorder);
        }

        return root;
    }

    int getVectorIndex(vector<int>& v, int target) {
        if (v.empty())
            return -1;

        vector<int>::iterator ite = find(v.begin(), v.end(), target);
        int index = distance(v.begin(), ite);

        return index;
    }
};
```