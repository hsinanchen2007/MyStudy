中序遍历，每次判断当前节点和上一节点是否满足顺序关系，若有不满足则直接返回false

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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> sta;
        if(root==NULL) return true;
        TreeNode* currNode = NULL;
        while(!sta.empty()|| root!=NULL)
        {
            while(root!=NULL){
                sta.push(root);
                root = root->left;
            }

            root = sta.top();
            sta.pop();
            if(currNode!=NULL && (currNode->val>=root->val)) return false;
            currNode = root;
            root = root->right;

        }
        return true;
    }
};
```