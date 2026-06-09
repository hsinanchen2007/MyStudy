### 解题思路

1. 根据前序的结果，用**第一个值**初始化当前子树的root节点
2. 在中序的结果中查找root节点
3. 从前序的结果中获取左子树的前序结果，从中序的结果中获取左子树的中序结果，返回结果1
4. 从前序的结果中获取右子树的前序结果，从中序的结果中获取右子树的中序结果，返回结果1

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
    TreeNode* recBuild(vector<int> preorder, vector<int> inorder) {
        // init root, first value of preorder is root
        TreeNode* root = new TreeNode();    root->val = preorder[0];
        root->left = root->right = nullptr;

        if (preorder.size() == 1 && inorder.size() == 1) {
            return root;
        }

        int pivot;
        for (int i = 0; i < inorder.size(); i++) {
            if (root->val == inorder[i]) {
                pivot = i;
                break;
            }
        }
    
        if (pivot > 0) {
            vector<int> leftInorder(inorder.begin(), inorder.begin() + pivot);
            vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + pivot + 1);
            root->left = recBuild(leftPreorder, leftInorder);
        }
        
        if (pivot < (preorder.size() - 1)) {
            vector<int> rightInorder(inorder.begin() + pivot + 1, inorder.end());
            vector<int> rightPreorder(preorder.begin() + pivot + 1, preorder.end());
            root->right = recBuild(rightPreorder, rightInorder);
        }

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return nullptr;

        return recBuild(preorder, inorder);
    }
};
```