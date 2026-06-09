### 解题思路

和102题一样，102题是每次加入一层的元素，这一题是获取每一层的最大值。

### 代码

```cpp
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;

        queue<TreeNode*> myque;
        myque.push(root);

        while ( ! myque.empty() ){
            int level_size = myque.size();
            int max = INT_MIN;
            for (int i = 0; i < level_size; i++){
                TreeNode *node = myque.front();
                myque.pop();
                max = node->val > max ? node->val : max;

                if (node->left != NULL) myque.push(node->left);
                if (node->right != NULL) myque.push(node->right); 
            }
            res.push_back(max);
        }
        return res;

    }
};
```