
深度优先(DFS)一般都是利用递归实现，使用函数调用过程中的系统栈，而不是自己手写堆栈

递归的每一层逻辑是，获取当前root，左右的最大值，然后在此基础上加上本层，返回。

```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;

        int left_max = maxDepth(root->left);
        int right_max = maxDepth(root->right);

        return max(left_max, right_max) + 1;

    }
};
```

广度优先(BFS)只能是自己写queue，先进先出。

BFS的逻辑就是，一层一层的扫过去，记录每个节点的深度信息，

- 如果当前node不为NULL，
  - 如果当前node为NULL，说明 这个节点到头了，直接跳过
  - 否则，根据叶子节点的定义，左右子节点为空，才算是叶子节点，因此判断它左右节点是否为空，如果都为空，计算它的深度
  - 否则，假如它的子节点

最后返回max_depth

```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {

        queue<pair<TreeNode*, int>> q;
        q.push({root,1});

        int max_depth = 0;

        while ( ! q.empty() ){
            
            TreeNode* node = q.front().first;
            int depth = q.front().second;           
            q.pop();
            if ( node == NULL ) continue;
            if ( node->left == NULL && node->right == NULL){
                max_depth = max(max_depth, depth);
            } else{
                q.push( {node->left, depth+1});
                q.push( {node->right, depth+1});
            }

        }

        return max_depth;

    }
}
```