### 解题思路
用指针把实例化该办的事儿都办了， 一个指新链表的头，一个跟踪当前节点的前驱（传参也是这个思路，只是能少粘一次就少一嘛）

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
    TreeNode* convertBiNode(TreeNode* &root) {
        // 10^5 >> O < T:O(NlogN)
        // inOrder compleate srch L2R >> O(N) 
        // eachNode.left = NULL
        if (root == NULL)
            return NULL;                
        build(root);
        return newRoot;
    }
private:
    TreeNode* newRoot {NULL};
    TreeNode* pre {NULL};
    void build (TreeNode* root){
        if (root == NULL)
            return;
        convertBiNode(root->left);        
        if (newRoot == NULL){            
            newRoot = root;            
        }            
        root->left = NULL;
        if (pre)
            pre->right = root;
        pre = root;            
        convertBiNode(root->right);        
        return;        
    }
};
```