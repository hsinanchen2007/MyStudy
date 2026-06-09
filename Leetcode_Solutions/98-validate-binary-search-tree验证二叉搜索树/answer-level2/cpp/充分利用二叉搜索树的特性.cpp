## 中序遍历
执行用时 :
12 ms
, 在所有 C++ 提交中击败了
97.61%
的用户
内存消耗 :
20.5 MB
, 在所有 C++ 提交中击败了
79.38%
的用户

```C++ {}
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* p = root;
        stack<TreeNode*> st;
        long inorder = LONG_MIN;
        while(p || !st.empty()){
            while(p){
                st.push(p);
                p = p->left;
            }
            p = st.top();
            st.pop();
            if(p->val <= inorder) return false;
            inorder = p->val;
            p = p->right;
            
        }
        return true;
    }
};

```
因为二叉搜索树的中序遍历一定是从小到大的，因此中序遍历一下，把上一个遍历的结果保存下来，比较这次即将遍历的数字就行了
