### 解题思路
1、根据后序遍历确定根节点。
2、根据中序遍历，确定左子树和右子树。
3、递归求解。

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0){
            return NULL;
        }
        int i = 0;
        for(i = 0; i<inorder.size(); i++){
            if(postorder.back() == inorder[i]){
                break;
            }
        }
        vector<int> inLeft(inorder.begin(), inorder.begin()+i);
        vector<int> inRight(inorder.begin()+i+1, inorder.end());
        vector<int> postLeft(postorder.begin(), postorder.begin()+i);
        vector<int> postRight(postorder.begin()+ i, postorder.end()-1);
        TreeNode* root = new TreeNode(postorder.back());
        root->left = buildTree(inLeft, postLeft);
        root->right = buildTree(inRight, postRight);
        return root;
    }
};
```