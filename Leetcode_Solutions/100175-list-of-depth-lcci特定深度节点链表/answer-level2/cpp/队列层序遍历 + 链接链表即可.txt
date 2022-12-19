### 解题思路

![image.png](https://pic.leetcode-cn.com/d73c7bef15c417b2079560389150f62ba51ad294fb77bcf07cde5995949d509c-image.png)

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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        vector<ListNode*> result;
        queue<TreeNode*> queTree;
        TreeNode* curNode = NULL;
        ListNode* curListNode = NULL;
        ListNode* newListNode = NULL; 

        if (tree)queTree.push(tree);
        while (!queTree.empty())
        {
            int size = queTree.size();
            for (int i = 0; i < size; i++)
            {   
                curNode = queTree.front();
                queTree.pop();
                newListNode = new ListNode(curNode->val);
                if (i == 0) 
                {
                    result.emplace_back(newListNode);
                    curListNode = newListNode;
                }
                else
                {
                    curListNode->next = newListNode;
                    curListNode = curListNode->next;
                }
                if (curNode->left) queTree.push(curNode->left);
                if (curNode->right) queTree.push(curNode->right);
            }
        }
        return result;
    }
};
```