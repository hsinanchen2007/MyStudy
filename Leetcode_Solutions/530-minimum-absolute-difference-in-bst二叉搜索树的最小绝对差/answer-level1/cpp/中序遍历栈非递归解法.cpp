### 解题思路
即是二叉搜索树，中序遍历 + 最小前继结点和当前结点差绝对值即可

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
    int getMinimumDifference(TreeNode* root) {
        stack<TreeNode*> stkNode;
        int minAbs = INT_MAX;
        TreeNode* curNode = root;
        TreeNode* preNode = NULL;

        while(!stkNode.empty() || curNode)
        {
            while(curNode)
            {
                stkNode.push(curNode);
                curNode = curNode->left;
            }
            curNode = stkNode.top();
            stkNode.pop();
            if (preNode)
            {
                minAbs = min(minAbs,abs(preNode->val - curNode->val));
            }
            preNode = curNode;
            curNode = curNode->right;
        }
        return minAbs;
    }
};
```