### 解题思路
详情见代码

解法1、递归

```
复杂度
        1、时间复杂度：O(n)，因为我们遍历整个输入树一次，所以总的运行时间为 O(n)，其中 n 是树中结点的总数。
        
        2、空间复杂度：递归调用的次数受树的高度限制。在最糟糕情况下，树是线性的，其高度为 O(n)。因此，在最糟糕的情况下，由栈上的递归调用造成的空间复杂度为 O(n)。
```

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
    bool flag = true; 
    bool dfs(TreeNode* left, TreeNode* right) {
        if(!left && !right) return true;  // left和right均为空结点时为结束条件
        else if(left && right && left->val == right->val) {  // 左右子树不为空且值相等
            dfs(left->left, right->right);  // 左子树向左走的同时右子树向右走
            dfs(left->right, right->left);  // 左子树向右走的同时右子树向左走
        }
        else return flag = false;  // 左右子数任一为空或者左右子树值不相等则非镜像对称 
        return flag;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return dfs(root->left, root->right);
    }
};
```

解法2、队列(bfs)

```
复杂度
    1、时间复杂度：O(n)，因为我们遍历整个输入树一次，所以总的运行时间为 O(n)，其中 nn 是树中结点的总数。
    2、空间复杂度：搜索队列需要额外的空间。在最糟糕情况下，我们不得不向队列中插入 O(n) 个结点。因此，空间复杂度为 O(n)
```

```cpp
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);
        while(!q.empty()) {
            TreeNode* t1 = q.front();
            q.pop();
            TreeNode* t2 = q.front();
            q.pop();
            if(!t1 && !t2) continue;
            if(!t1 || !t2) return false;
            cout<<t1->val<<" "<<t2->val<<endl;
            if(t1->val == t2->val) {
                //这里push的思想和上面递归的一样
                q.push(t1->left);
                q.push(t2->right);
                q.push(t1->right);
                q.push(t2->left);
            }
            else return false;
        }
        return true;
    }
};
```

```
附录：
    1、递归算法的时间复杂度为：递归总次数 * 每次递归中基本操作所执行的次数
    2、递归算法的空间复杂度：递归深度N*每次递归所要的辅助空间， 如果每次递归所需的辅助空间是常数，则递归的空间复杂度是 O(N).

```