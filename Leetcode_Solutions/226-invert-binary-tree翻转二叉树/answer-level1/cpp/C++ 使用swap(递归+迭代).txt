### 解题思路
我最开始的思路是：**反序中序遍历用队列保存节点值，然后再中序遍历将队首元素赋值给当前节点**，但是我又看一眼题目，发现不对劲。这不是满二叉树，这样的做法当然是不对的啦~~

从最简单的情况开始想：

**只有一个根节点的情况**
![简单情况](https://pic.leetcode-cn.com/5fc8c3368811ce7ceabad0dfd85c056556b1cfce2347e7b2283efaa8d3718f6d)

翻转二叉树的时候只需要将根节点的左右孩子交换即可：`swap(root->left, root->right)`

所以呢，递归就完事啦~~~


#### 递归代码

```cpp
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
      dfs(root);
      return root;
    }
private:
    void dfs(TreeNode* root){
        if(root){
            swap(root->left, root->right);
            dfs(root->left);
            dfs(root->right);
        }
    }
};
```

将上述的递归代码改为迭代方式：
+ 类似二叉树的层序遍历，每次向队列中添加当前层的节点；
+ 不断弹出队列，将队首元素的左右孩子进行交换 `swap`
#### 迭代代码
```cpp
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
      if(!root) return nullptr;
      queue<TreeNode*> q;
      q.push(root);
      while(!q.empty()){
          int size = q.size();
          while(size--){
              TreeNode* tmp =  q.front();
              q.pop();
              if(tmp){
                  swap(tmp->left, tmp->right);
                  q.push(tmp->left);
                  q.push(tmp->right);
              }
          }
      }
      return root;
    }
```