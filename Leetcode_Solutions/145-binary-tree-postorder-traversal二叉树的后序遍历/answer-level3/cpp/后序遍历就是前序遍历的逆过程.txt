[截图未命名.jpg](https://pic.leetcode-cn.com/2c1cdb926b6450c613780772b7304975e6dfa862290307452d89e077f609736e-%E6%88%AA%E5%9B%BE%E6%9C%AA%E5%91%BD%E5%90%8D.jpg)
只需将前序遍历交换左右子树入栈次序，最后把vector进行reverse就行了。
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(!root) return ret;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* p=st.top();
            st.pop();
            ret.push_back(p->val);
            if(p->left) st.push(p->left);
            if(p->right) st.push(p->right);
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};