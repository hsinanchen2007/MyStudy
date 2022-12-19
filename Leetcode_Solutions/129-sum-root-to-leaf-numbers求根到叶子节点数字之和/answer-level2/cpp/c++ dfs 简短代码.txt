思路：从根节点到叶子节点dfs,把到目前为止的和传递给左右子节点，在叶子节点的时候加起来
![image.png](https://pic.leetcode-cn.com/aa33115635408a3ff31abc21e18cb88d6f3929d6495d6c7f75525d67ad0158c0-image.png)


```
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(root == NULL)return 0;
        stack<pair<TreeNode*, int>> st;
        st.push({root, 0});
        pair<TreeNode*, int> np;
        TreeNode* node;
        int ans = 0, v;
        while(!st.empty()){
            np = st.top();
            st.pop();
            node = np.first;
            v = np.second;
            if(node->left == NULL && node->right == NULL){
                ans += v*10 + node->val;
            }
             if(node->left != NULL){
                st.push(make_pair(node->left, v*10+node->val));
            }
            if(node->right != NULL){
                st.push(make_pair(node->right, v*10+node->val));
            }
        }
        return ans;
    }
};
```