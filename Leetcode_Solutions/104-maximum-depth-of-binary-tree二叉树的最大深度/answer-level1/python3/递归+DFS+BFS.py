## 二叉树递归套路解法：

对于需要向左右子节点索取信息的问题，可以使用如下递归套路。

1、对每个节点进行可能性分析，判断是return false 还是return true。

2、递归实现功能。

if 根节点满足某种条件

+ return 递归(左子树) && 递归(右子树) 

+ return (递归(左子树) || 递归右子树) （其中一个满足条件即可）

return false

```python []
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if root == None: return 0
        return max(self.maxDepth(root.left) + 1, self.maxDepth(root.right) + 1)
```
```C++ []
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        return max(maxDepth(root->left)+1, maxDepth(root->right)+1); 
    }
};
```
## DFS 深度优先遍历

递归实际上就是系统使用栈进行遍历操作，任何递归都可以使用栈写成迭代的形式，其中前序遍历、
中序遍历和后续遍历都属于深度优先变量，这里C++代码在中序遍历的基础上加入了位置信息，实现
了深度计算


```python []
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if root is None:return 0
        stack = [(root, 1)]
        deep = 0
        Maxdeep = 0
        while stack:
            node, deep= stack.pop()
            Maxdeep = max(Maxdeep, deep)
            if node.right:
                stack.append((node.right, deep+1))
            if node.left:
                stack.append((node.left, deep+1))
        return Maxdeep
```
 
```C++ []
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        stack <pair<TreeNode* , int>> s;
        int Maxdeep = 0;
        int deep = 0;
        while (!s.empty() || root){
            if(root){
                s.push(pair<TreeNode*,int>(root,++deep));
                root = root->left;
            }
            else {
                root = s.top().first;
                deep = s.top().second;
                Maxdeep = max(Maxdeep, deep);
                s.pop();
                root= root->right;   
            }
        }
        return Maxdeep;
    }
};
```

## BFS 广度优先遍历

广度优先遍历实际上就是层次遍历，一般采用队列实现

```python []
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if root is None:
            return 0
        queue = [(root, 1)]
        while queue:
            node, deep = queue.pop(0)
            if node.left:
                queue.append((node.left, deep+1))
            if node.right:
                queue.append((node.right, deep+1,))
        return deep
```
```C++ []
class Solution {
public:
    int maxDepth(TreeNode* root) {
         if(root==NULL) return 0;
         deque<TreeNode*> q;
         TreeNode* p;
         q.push_back(root);
         int deep=0, length = 0;
         while(!q.empty()){
             deep++;
             length = q.size();
             for(int i = 1; i <= length; i++){
                p = q.front();
                q.pop_front();
                if(p->left) q.push_back(p->left);
                if(p->right) q.push_back(p->right);
             }
         }
         return deep;         
    }
};
```

本题递归最慢，因为递归内部使用栈访问叶结点三次，而迭代的方法使用栈的次数会少一些