### 解题思路
首先注意nullptr的判断
其次为了逻辑清晰和运算方便，每次push与pop应保证每层再双端队列中的顺序和原来的树相应层节点顺序完全相同
此时再判断为了实现从左往右或从右往左应该时front 还是Back
此题从左往右遍历，应该是取前端，放入后端
从右往左是取后端，放入前端，并且左右节点push顺序颠倒

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr){
            return {};
        }
        deque<TreeNode*> tree_deque;
        tree_deque.push_back(root);
        int flag = 0;
        int level_size = 1;
        vector<vector<int>> ans;
        while(!tree_deque.empty()){
            vector<int> level_ans; 
            if (flag == 0){
                for(int i = 0;i<level_size;i++){
                    level_ans.push_back(tree_deque.front()->val);
                    if (tree_deque.front()->left){
                        tree_deque.push_back(tree_deque.front()->left);
                    }
                    if(tree_deque.front()->right)
                        tree_deque.push_back(tree_deque.front()->right);
                    tree_deque.pop_front();
                }
            }
            else if (flag == 1){
                for(int i = 0;i<level_size;i++){
                    level_ans.push_back(tree_deque.back()->val);
                    if (tree_deque.back()->right){
                        tree_deque.push_front(tree_deque.back()->right);
                    }
                    if(tree_deque.back()->left)
                        tree_deque.push_front(tree_deque.back()->left);
                    tree_deque.pop_back();
                }
            }
            level_size = tree_deque.size();
            ans.push_back(level_ans);
            flag = 1-flag;
        } 
    return ans;
    }
};
```