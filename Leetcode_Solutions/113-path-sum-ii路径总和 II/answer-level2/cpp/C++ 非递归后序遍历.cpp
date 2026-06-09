### 解题思路
主要思路：非递归后序遍历，栈的内容是当前节点的所有根节点（利用这个性质可以做很多题）；

如果当前节点为叶节点，且当前和 与 目标和相等，将当前栈内容存起来。

可以参考 [145. 二叉树的后序遍历](https://leetcode-cn.com/problems/binary-tree-postorder-traversal/solution/c-die-dai-shuang-bai-qian-zhong-hou-zong-jie-by-gw/)
以及 [112. 路径总和](https://leetcode-cn.com/problems/path-sum/solution/lu-jing-zong-he-by-leetcode/)
官方题解的方法二。

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root) return {};
        vector<vector<int>> res;
        TreeNode* prev = root;

        vector<pair<TreeNode*,int>> tree_st;
        tree_st.push_back({root,sum-root->val});

        while(!tree_st.empty()){
            auto cur_pair = tree_st.back();
            auto cur_sum = cur_pair.second;
            auto cur = cur_pair.first;
            if(cur->left && cur->left!= prev && cur->right!=prev){
                tree_st.push_back({cur->left,cur_sum-cur->left->val});
            }else if(cur->right && cur->right!=prev){
                tree_st.push_back({cur->right,cur_sum-cur->right->val});
            }else{
                
                if(!cur->left && !cur->right && cur_sum==0){
                    vector<int> cur_path;
                    for_each(tree_st.cbegin(),tree_st.cend(),
                        [&cur_path](auto& p1){cur_path.push_back(p1.first->val);});
                    
                    res.push_back(cur_path);
                    cur_path.clear();
                }
                
                tree_st.pop_back();
                prev = cur;
            }
        }
        return res;
    }



    
};
```

### 提交结果

![image.png](https://pic.leetcode-cn.com/c7138b495c844dc0f669c433453f45c1620efa6ca01cf9bb858c43cdba2e435f-image.png)
