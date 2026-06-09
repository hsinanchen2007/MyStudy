对二叉树进行贪心运算，在每个节点上尽可能不放置监控。

每个节点的状态有 3 个：2 为放置监控，1 为被监控，0 为未被监控。当所遍历的节点的任一子节点未被监控时，当前节点必须放置监控即为 2；当所遍历的节点的任一子节点放置了监控时，当前节点必须为被监控即为 1；其余情况均为未被监控即为 0。

借用栈对二叉树进行后序遍历，保证了二叉树自下向上推算，每个节点均能够根据其已遍历的子节点来推算出当前节点状态。遍历并累计所有放置监控的节点数。

最后如果 root 节点为未被监控，最后返回的监控数量需加一。

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
    int minCameraCover(TreeNode* root) 
    {
        if (root == NULL)
        {
            return 0;
        }

        int count = 0;
        stack<TreeNode*> NodeStack;
        unordered_map<TreeNode*, int> NodeMap;       // 元素有三个状态：2 为放置监控，1 为被监控，0 为未被监控
        TreeNode* pNode = root;
        while (!NodeStack.empty() || pNode != NULL)
        {
            while (pNode != NULL)
            {
                NodeStack.push(pNode);
                pNode = pNode->left;
            }

            while (!NodeStack.empty() && (NodeStack.top()->right == NULL || pNode == NodeStack.top()->right))
            {
                pNode = NodeStack.top();
                NodeStack.pop();

                if ((pNode->left != NULL && NodeMap[pNode->left] == 0) || 
                    (pNode->right != NULL && NodeMap[pNode->right] == 0))
                {
                    NodeMap[pNode] = 2;
                    count++;
                }
                else if ((pNode->left != NULL && NodeMap[pNode->left] == 2) || 
                         (pNode->right != NULL && NodeMap[pNode->right] == 2))
                {
                    NodeMap[pNode] = 1;
                }
                else
                {
                    NodeMap[pNode] = 0;
                }           
            }
            
            pNode = !NodeStack.empty() ? NodeStack.top()->right : NULL;
        }     

        return NodeMap[root] == 0 ? count + 1 : count;  
    }
};
```
