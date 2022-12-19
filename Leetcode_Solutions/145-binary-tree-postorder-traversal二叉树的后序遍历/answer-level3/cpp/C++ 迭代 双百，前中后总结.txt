## 解题思路

后序遍历思路：左右根

## 代码

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
        if(!root) return {};
        vector<int> res;
        TreeNode* prev = root;
        stack<TreeNode*> tree_st;
        tree_st.push(root);

        while(!tree_st.empty()){
            auto cur = tree_st.top();
            if(cur->left && cur->left!= prev && cur->right!=prev){
                tree_st.push(cur->left);
            }else if(cur->right && cur->right!=prev){
                tree_st.push(cur->right);
            }else{
                res.push_back(cur->val);
                tree_st.pop();
                prev = cur;
            }
        }
        return res;
    }
};
```



## 提交结果
![image.png](https://pic.leetcode-cn.com/89fb47d8942cc0be4557c7856d7d9169ed44ffd5bf54b678ecb6c7c04735747a-image.png)



# 附：
## 前序
```
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> tree_st;
        auto temp = root;
        //tree_st.push()
        while(!tree_st.empty() || temp){
            while(temp){
                tree_st.push(temp);
                res.push_back(temp->val);
                temp = temp->left;
            }
            temp = tree_st.top();
            temp = temp->right;
            tree_st.pop();

        }

        return res;
    }
```

## 中序

```
vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> tree_st;
        auto temp = root;
       
        while(!tree_st.empty() || temp){
            while(temp){
                tree_st.push(temp);
                
                temp = temp->left;
            }
            temp = tree_st.top();
            res.push_back(temp->val);
            temp = temp->right;
            tree_st.pop();

        }

        return res;
    }
```



