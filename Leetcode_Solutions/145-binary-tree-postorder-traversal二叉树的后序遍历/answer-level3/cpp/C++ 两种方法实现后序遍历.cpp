### 解题思路

**方法1：**
+ 可以结合前序遍历，我们对树做`根节点-右子树-左子树`顺序遍历，再对结果反转即可

**方法2：**
+ 后序遍历和中序前序遍历的区别在于，要区分什么时候根节点要输出
+ 所以记录当前节点的右子树是否为空或者是否访问过

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
        vector<int> v;
        if(!root) return v;
        stack<TreeNode*> st;
        // 方法1. 类前序遍历的反转 ： 根->右->左
        /*
        while(!st.empty() || root){
            while(root){
                v.push_back(root->val);
                st.push(root);
                root = root->right;
            }
            if(!st.empty()){
                root = st.top()->left;
                st.pop();
            }
        }
        reverse(v.begin(), v.end());
        */

        // 方法2. 保存前级指针
        TreeNode* prev = nullptr;
        while(!st.empty() || root){
            while(root){
                st.push(root);
                root = root->left;
            }
            root = st.top();
            // 如果该节点的右子树为空或者右子树已经访问过
            if(root->right == nullptr || root->right == prev){
                v.push_back(root->val);
                st.pop();
                prev = root;
                root = nullptr;
            }else{
                root = root->right;
            }

        }
        return v;
    }
};
```