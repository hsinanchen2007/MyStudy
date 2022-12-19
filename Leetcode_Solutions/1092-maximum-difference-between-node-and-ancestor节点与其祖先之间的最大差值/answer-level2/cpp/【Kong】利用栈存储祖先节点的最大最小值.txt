### 借用栈完成后序遍历

借用栈进行的后序遍历，当前节点的祖先节点均在栈中，分别计算当前节点与栈中节点的最大值和最小值的差值。

时间复杂度 O(logn)，空间复杂度 O(n)。

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
    int maxAncestorDiff(TreeNode* root) 
    {
        int rst = 0;
        multiset<int> NodeSet;
        stack<TreeNode*> NodeStack;
        TreeNode* pNode = root;
        while (pNode != NULL || !NodeStack.empty())
        {
            while (pNode != NULL)
            {
                NodeStack.push(pNode);
                NodeSet.insert(pNode->val);
                pNode = pNode->left;
            }          

            while (!NodeStack.empty() && (NodeStack.top()->right == NULL || pNode == NodeStack.top()->right))
            {
                int NodeVal = NodeStack.top()->val;
                multiset<int>::iterator set_iterator = NodeSet.begin();
                int tmp = NodeVal > *set_iterator ? NodeVal - *set_iterator : *set_iterator - NodeVal;
                rst = std::max(rst, tmp);
                set_iterator = NodeSet.end();
                set_iterator--;
                tmp = NodeVal > *set_iterator ? NodeVal - *set_iterator : *set_iterator - NodeVal;
                rst = std::max(rst, tmp);
                NodeSet.erase(NodeSet.find(NodeVal));

                pNode = NodeStack.top();
                NodeStack.pop();
            }   

            pNode = !NodeStack.empty() ? NodeStack.top()->right : NULL;
        }

        return rst;
    }
};
```

### 递归完成后序遍历

递归进行后序遍历。在每层级递归中，先计算包含当前节点与其祖先节点的最大节点与最小节点，然后作为祖先节点的最大节点与最小节点传递给左子树与右子树。递归返回的当前节点作为根节点时其子树各节点与祖先节点的最大差值。

时间复杂度 O(logn)，空间复杂度 O(logn)。

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
    int dfs(TreeNode* root, int MaxVal, int MinVal)
    {
        if (root == NULL)
        {
            return 0;
        }
        
        MaxVal = std::max(root->val, MaxVal);
        MinVal = std::min(root->val, MinVal);

        int LeftDiff = dfs(root->left, MaxVal, MinVal);
        int RightDiff = dfs(root->right, MaxVal, MinVal);
        int CurtDiff = std::max(root->val - MinVal, MaxVal - root->val);

        return std::max(std::max(LeftDiff, RightDiff), CurtDiff);
    }

    int maxAncestorDiff(TreeNode* root) 
    {
        return dfs(root, INT_MIN, INT_MAX);    
    }
};
```
