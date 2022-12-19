### 解题思路
### 广度优先搜索：
1. 分别用两个队列存储待扩展的元素和其深度
2. 每次从队列中弹出队头元素进行访问，将其val加入到对应深度的vector中，直到队列为空

**广度优先搜索实现**

```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> q;
        queue<int> dep;
        if(root) {
            q.push(root);
            dep.push(0);
        }
        else return result;
        while(!q.empty()){
            TreeNode* node = q.front(); q.pop();
            int d = dep.front(); dep.pop();
            if(d==result.size()) result.emplace_back();
            result[d].push_back(node->val);
            if(node->left != NULL){
                q.push(node->left);
                dep.push(d+1);
            } 
            if(node->right != NULL){
                q.push(node->right);
                dep.push(d+1);
            }
        }
        return result;
    }
};
```

### 深度优先搜索
1. 本题要求逐层遍历，而且左到右，注意到不同层的节点的val是放在不同的vector中的。所以对于递归实现的前序、中序、后序遍历均可保证层次要求。比如说根节点放在第0层，它的左右节点放在第一层，所以第0层和第一层的节点分别放在不同的数组。即以下三种实现顺序都可以满足逐层遍历要求：
```
    前序：
        result[dep].push_back(root->val);
        dfs(root->left, dep+1);
        dfs(root->right, dep+1);
    中序：
        dfs(root->left, dep+1);
        result[dep].push_back(root->val);
        dfs(root->right, dep+1);
    后序：
        dfs(root->left, dep+1);
        dfs(root->right, dep+1);
        result[dep].push_back(root->val);

```



2. 而左右节点的顺序，只要先搜索左子树，再进行搜索右子树，即可保证从左到右的顺序。
```严格要求先访问左子树
        dfs(root->left, dep+1);
        dfs(root->right, dep+1);
```


**深度优先搜索实现**
```
class Solution {
public:
    vector<vector<int>> result;
    void dfs(TreeNode* root, int dep){
        if(!root) return;
        if(dep == result.size()) result.emplace_back();
        result[dep].push_back(root->val);
        dfs(root->left, dep+1);
        dfs(root->right, dep+1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
      dfs(root, 0);
      return result;
    }
};

```
