### 1. 广度优先搜索

如果这棵树是一棵满二叉树，那么肯定很多小伙伴就会觉得很简单了，只要判断每一层的数据是否回文就可以啦~

但是现在不是满二叉树，难道这样就该难倒我们么？

不就是有空节点么，对空节点的值用其他代替不就好了么。

+ 如果一个节点不为空，就将它的左右节点都添加到队列中
+ 如果当前节点为空，则其值用`INT_MIN`来代替，不添加左右节点
+ 每层判断是否回文

```cpp
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> v(size);
            for(int i = 0; i<size; ++i){
                root = q.front(); q.pop();
                v[i] = root ? root->val : INT_MIN;
                if(root) { q.push(root->left); q.push(root->right); }
            }
            // 判断是否回文
            for(int i = 0; i< size/2; ++i){
                if(v[i] != v[size-1-i]) return false;
            }
        }
        return true;
    }
};
```

### 2. 深度优先搜索

用深度优先搜索呢？该怎么做呢？

很简单，怎么判断是否镜像呢，我们需要两个指针来镜像比较。

一个指针`root1`在左子树，另一个指针`root2`在右子树；
比较`root1->left == root2->right` 和 `root1->right == root2->left`,也就是镜像比较。

```cpp
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return dfs(root->left, root->right);
    }
private:
    bool dfs(TreeNode* root1, TreeNode* root2){
        if(!root1 && !root2) return true;
        if(!root1 || !root2) return false;
        if(root1->val != root2->val) return false;
        return dfs(root1->left, root2->right) && dfs(root1->right, root2->left);
    }
};
```