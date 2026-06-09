### 首先最直观会想到一层一层的遍历，直到找到叶子阶段，因此层序遍历 = BFS，使用队列queue来处理
参考了其他多个大佬的题解，以自己觉得简洁易懂的方式写出来

### 代码

solution1 BFS层序遍历
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

// BFS
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        
        // 使用队列queue做BFS
        queue<TreeNode*> que;
        que.push(root);
        int minDepth = 1;
        while(!que.empty()) {
            auto size = que.size();
            while(size--) {  /* pop 处理完该层的所有节点， 要注意pop的次数  BFS中这步很关键  */
                auto node = que.front();    que.pop();
                if(node->left==nullptr && node->right==nullptr)  return minDepth;
                if(node->left)      que.push(node->left);
                if(node->right)     que.push(node->right);
            }
            minDepth++;
        }
        return minDepth;
    }
};
```

**solution 2 求解树相关的问题，通常都可以用递归解决，难点处理边界条件**
3种情况：
1. 节点左右子树都空，直接返回0；
2. 节点左、右子树有一个为空，因此对应leftDep，rightDep 有一个 = 0；该节点的minDepth 就是 max(leftDep, rightDep) + 1, 或者像其他大佬的写法 leftDep+rightDep+1 也一样的。
3. 节点的左右子树都不为空，那么就是min(leftDep, rightDep) + 1 了

```cpp
class Solution {
public:
    int minDepth(TreeNode* root) {

        if(root==nullptr) return 0;
        
        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);
        
        if(leftDepth==0 || rightDepth==0)  // 左右子树有一个为空的情况
        // if(root->left==nullptr || root->right==nullptr)
            return leftDepth + rightDepth + 1;
        
        // 左右子树都不为空，当然选dep小的
        return min(leftDepth, rightDepth) + 1;
    }
};
```