## 解法：

此题本质上是一个二叉树的广度优先遍历问题，但与一般的广度优先遍历不同，需要将同一层次的结点存储在同一个`vector`中。为了解决此问题，只需要在遍历的同时记录结点的深度即可。

```c++
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr)
            return vector<vector<int>>(); 
        queue<pair<TreeNode*, int>> node_queue;
        node_queue.push(make_pair(root, 0));

        vector<vector<int>> result;
        int last_level = -1;
        while (!node_queue.empty()){
            TreeNode* current_node = node_queue.front().first;
            int current_level = node_queue.front().second;
            node_queue.pop();
            if (current_level != last_level){
                result.emplace_back(vector<int>({current_node->val}));
                last_level = current_level;
            } else {
                result[current_level].push_back(current_node->val);
            }
            if (current_node->left != nullptr)
                node_queue.push(make_pair(current_node->left, current_level + 1));
            if (current_node->right != nullptr)
                node_queue.push(make_pair(current_node->right, current_level + 1));
        }

        return result;
    }
};
```