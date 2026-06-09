### 解题思路

非递归后序遍历，每个节点被访问的时候，栈里面内容都是其所有根节点。
（本题栈结构选用了vector实现,为了遍历）
可以参考 [145. 二叉树的后序遍历](https://leetcode-cn.com/problems/binary-tree-postorder-traversal/solution/c-die-dai-shuang-bai-qian-zhong-hou-zong-jie-by-gw/)

### 代码

```cpp

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(!root) return {};
        int res = 0;
        TreeNode* prev = root;
        vector<TreeNode*> tree_st;
        tree_st.push_back(root);

        while(!tree_st.empty()){
            auto cur = tree_st.back();
            if(cur->left && cur->left!= prev && cur->right!=prev){
                tree_st.push_back(cur->left);
            }else if(cur->right && cur->right!=prev){
                tree_st.push_back(cur->right);
            }else{
                //到了叶节点，正序遍历栈
                if(!cur->left && !cur->right){
                    int cur_int = 0;
                    for_each(tree_st.cbegin(),tree_st.cend(),
                        [&cur_int](auto& ptr){cur_int = cur_int*10; cur_int+=ptr->val;});
                    //cout<<cur_int<<endl;
                    res += cur_int;
                }


                tree_st.pop_back();
                prev = cur;
            }
        }
        return res;
    }

};
```

### 结果
![image.png](https://pic.leetcode-cn.com/6f445d18ae952ff15d2a56ed00c41fcf96583e05a8f7e6addc2f556b000d08e6-image.png)
