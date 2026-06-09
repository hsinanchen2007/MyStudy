中序遍历
中序遍历得到的list中每个元素都应该比下一个元素小。

```
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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode *> stackList;
        if (root == NULL) {
            return true;
        }

        TreeNode *tempNode = root;
        long tempVal = LONG_MIN;

        while (tempNode != NULL || !stackList.empty()) {
            while (tempNode != NULL) {
                stackList.push(tempNode);
                tempNode = tempNode->left;
            }

            tempNode = stackList.top();
            stackList.pop();
            if (tempVal >= tempNode->val ) {
                return false;
            }

            tempVal = tempNode->val;

            tempNode = tempNode->right;
        }

        return true;
    }
};
```
