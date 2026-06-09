二叉树遍历中最简单的一个遍历方式

```
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        stack<TreeNode*> st;
        st.push(root);
        while(st.size()){
          auto curr = st.top();
          st.pop();
          ans.push_back(curr->val);
          if(curr->right) st.push(curr->right);
          if(curr->left) st.push(curr->left);
        }
        return ans;
    }
```
![image.png](https://pic.leetcode-cn.com/1ac3d88193508d0a49a702f0f3eeeb99025d1ed51b01022f9fa3060baac8751e-image.png)