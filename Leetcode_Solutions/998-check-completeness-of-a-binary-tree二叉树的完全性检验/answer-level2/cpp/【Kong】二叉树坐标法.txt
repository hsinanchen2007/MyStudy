节点坐标的规则如下：左子节点坐标 = 根节点坐标 * 2，右子节点坐标 = 根节点坐标 * 2 + 1。

借用队列对二叉树进行层次遍历，并把非节点与其坐标入队。如果二叉树为完全二叉树，那么每一节点被广度遍历的顺序与其坐标相等。

时间复杂度 O(n)，空间复杂度 O(logn)。

* 示例 :

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
    bool isCompleteTree(TreeNode* root) 
    {
        if (root == NULL)
        {
            return true;
        }

        int count = 1;
        list<pair<TreeNode*,int>> NodeQueue;
        NodeQueue.push_back(pair<TreeNode*,int>(root, 1));
        while (!NodeQueue.empty())
        {
            int len = NodeQueue.size();
            for (int i = 0; i < len; i++)
            {
                int coordinate = NodeQueue.front().second;
                if (count != coordinate)
                {
                    return false;
                }
                if (NodeQueue.front().first->left != NULL)
                {
                    NodeQueue.push_back(pair<TreeNode*,int>(NodeQueue.front().first->left, coordinate * 2));
                }
                if (NodeQueue.front().first->right != NULL)
                {
                    NodeQueue.push_back(pair<TreeNode*,int>(NodeQueue.front().first->right, coordinate * 2 + 1));
                }
                NodeQueue.pop_front();
                count++;
            }
        }

        return true;   
    }
};
```
