### 解题思路
1.先基于dfs算法遍历出各节点
2.遍历各叶子节点，递归比较是否为子串

### 代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (head == NULL || root == NULL) {
            return false;
        }
        vector<TreeNode*> tmplistTreeNode;
        vector<TreeNode*> listTreeNode;
        tmplistTreeNode.push_back(root);
        listTreeNode.push_back(root);
        while (!tmplistTreeNode.empty()) {
            TreeNode* treeNode = tmplistTreeNode.back();
            tmplistTreeNode.pop_back();
            if (treeNode->right) {
                tmplistTreeNode.push_back(treeNode->right);
            }

            if (treeNode->left) {
                tmplistTreeNode.push_back(treeNode->left);
            }
            listTreeNode.push_back(treeNode);
        }
        for (int i = 0; i < listTreeNode.size(); i++) {
            if (isAvilablePath(head, listTreeNode[i])) {
                return true;
            }
        }
        return false;
    }

    bool isAvilablePath(ListNode* node, TreeNode* root) {
        if (node == NULL) {
            return true;
        }
        if (root == NULL) {
            return false;
        }

        if (root->val == node->val) {
            if (node->next == NULL) {
                return true;
            }
            return isAvilablePath(node->next, root->left)
            || isAvilablePath(node->next, root->right);
        } 
        return false;
    }
};
```