### 解题思路

用一个pre指针来表示上一个输出的节点的指针，在节点出栈的时候可以通过比较pre与节点的右指针是否相同来判断右子树是否已经被访问过

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        
        stack<TreeNode*> st;
        TreeNode* ptr = root;
        //用pre保存上一个输出的节点指针
        TreeNode* pre = nullptr;
        
        while(ptr || !st.empty()) {
            //循环将左孩子节点入栈
            while(ptr) {
                st.push(ptr);
                ptr = ptr->left;
            }

            ptr = st.top();
            //若上一个输出的节点是右孩子节点则出栈，否则将右孩子节点入栈
            if(ptr->right && pre != ptr->right) {
                ptr = ptr->right;
            } else {
                res.push_back(ptr->val);
                pre = ptr;
                st.pop();
                ptr = nullptr;
            }
        }

        return res;
    }
};
```