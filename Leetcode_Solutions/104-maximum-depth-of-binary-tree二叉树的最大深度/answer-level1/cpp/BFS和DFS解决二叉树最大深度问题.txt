

解法1、DFS（深度优先搜索）：可能会爆栈
```
    时间复杂度：O(n),每个结点只有进栈和出栈一次
    空间复杂度: 当树完全不平衡时，比如变成一条直链，复杂度是O(n)，若是完全平衡，则树高是log2（n）,复杂度是O(log2（n）)
```

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
    int dfs(TreeNode* root, int max_dept) {
        if(!root) return max_dept;
        int left_dept = dfs(root->left, max_dept+1);
        int right_dept = dfs(root->right, max_dept+1);
        return max(left_dept, right_dept);
    } 

    int maxDepth(TreeNode* root) {
        int max_dept = 0;
        return  dfs(root, max_dept);
    }
};
```

2、BFS（宽度优先搜索）：防止爆栈

```
    时间复杂度：O(n),每个结点只有进出队列一次
    空间复杂度: O(n),n为结点总数
```
```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int max_dept = 0;
        queue<pair<TreeNode*,int> >q;
        q.push({root, 1});
        while(!q.empty()) {
            TreeNode* curr_node = q.front().first;
            int curr_dept = q.front().second;
            q.pop();
            if(curr_node) {
                max_dept =  max(curr_dept, max_dept);
                q.push({curr_node->left, curr_dept+1});
                q.push({curr_node->right, curr_dept+1});
            }
        }
        return max_dept;
    }
};
```

