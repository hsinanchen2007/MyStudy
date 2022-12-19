### 解题思路
1.使用迭代的方法查找公共祖先。
2.如果p结点，和q结点的值都大于根结点，则迭代根节点的右子树。
3.如果p结点，和q结点的值都小于根结点，则迭代根节点的左子树。
4.当p结点和q结点的值对于根节点一大一小，或是一大一相等，或一小一相等，就返回根节点。

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        // Value of p
        int pVal = p->val;
        
        // Value of q
        int qVal = q->val;
        
        // Start from the root node of the tree
        TreeNode* node = root;
        
        // Traverse the tree
        while(node != NULL){
            
            // Value of ancestor/parent node
            int parentVal = node->val;
            
            if(pVal > parentVal && qVal > parentVal){
                
                // If both p and q are greater than parent
                node = node->right;
            }
            else if(pVal < parentVal && qVal < parentVal){
                
                // If both p and q are lesser than parent
                node = node->left;
            }
            else{
                
                // We have found the split point, i.e. the LCA node.
                return node;
            }
        }
        return NULL;
    }
};
```