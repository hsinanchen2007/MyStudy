### 解题思路
找出第一第二就行

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
    int findSecondMinimumValue(TreeNode* root) {
        int firstVal = INT_MAX;
        int secondVal = INT_MAX;
        int isHaveSecondVal = false;
        queue<TreeNode*> queNode;
        if (root)
        {
            queNode.push(root);
        }
        TreeNode* curNode;
        while (!queNode.empty())
        {
            int size = queNode.size();
            for (int i = 0; i < size; i++)
            {
                curNode = queNode.front();
                queNode.pop();
                if (curNode->val < firstVal)
                {
                    secondVal = firstVal;
                    firstVal = curNode->val;
                }
                else if (curNode->val == firstVal)
                {

                }
                else if (curNode->val <= secondVal)
                {
                    secondVal = curNode->val;
                    isHaveSecondVal = true;
                }

                if (curNode->left)
                {
                    queNode.push(curNode->left);
                }
                if (curNode->right)
                {
                    queNode.push(curNode->right);
                }
               
            }
        }
        return isHaveSecondVal ? secondVal : -1;
    }
};
```