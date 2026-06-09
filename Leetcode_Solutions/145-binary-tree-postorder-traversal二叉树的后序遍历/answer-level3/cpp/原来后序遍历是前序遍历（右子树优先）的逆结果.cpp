### 解题思路
**后序遍历**的递归代码结构很简单，像下面这样
orderTraversal(root->left);
orderTraversal(root->right);
cout<<root->val<<endl;

上面的遍历是**左子树优先**的，那么当我们把上面的**代码顺序反过来**，就变成了**右子树优先**的**前序遍历**
cout<<root->val<<endl;
orderTraversal(root->right);
orderTraversal(root->left);

也就是说，一般的后序遍历（左子树优先）的结果，是右子树优先的前序遍历的结果的**逆序**


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
        vector<int> ans;
        if(root==NULL) return ans;

        stack<TreeNode*> st;
        stack<TreeNode*> st2;
        TreeNode* cur = root;
        st.push(cur);
        while(!st.empty()){
            cur = st.top();
            st.pop();
            st2.push(cur);
            
             
            if(cur->left){
                st.push(cur->left);
            }
            if(cur->right){
                st.push(cur->right);
            }
           
        }
        while(!st2.empty()){
            cur = st2.top();
            st2.pop();
            ans.push_back(cur->val);
        }
        return ans;
       
    }
};
```