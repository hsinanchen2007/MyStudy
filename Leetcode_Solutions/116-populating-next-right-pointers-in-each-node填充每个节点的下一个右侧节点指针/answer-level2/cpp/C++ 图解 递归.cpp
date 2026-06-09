### 解题思路
如果这个问题不要求常数空间，那么BFS就可以解决了；所以我们可以使用递归来解决

对于递归的条件：
```
root 为根节点

1. 先连接根节点的左右孩子  root->left->next = root->right;
2. 再连接同层相邻节点的右孩子和左孩子 root->right->next = root->next->left;
3. 分别递归连接左右子树

递归停止的条件:
root->left不为空 （因为是完美二叉树，只判断左节点即可）
```

![binaryTree](https://pic.leetcode-cn.com/3a912d95fc77de4219713f32c934f37a53ff2975da45bc14dea4c1ca528a253c)

### 代码

```cpp
class Solution {
public:
    Node* connect(Node* root) {
        // 根节点为空
        if(!root) return root;
        dfs(root);
        return root;
    }

private:
    void dfs(Node* root){
        if(root->left){
            // 同一节点的左右孩子连接
            root->left->next = root->right;
            // 对同层相邻节点的右孩子和左孩子连接
            if(root->next){
                root->right->next = root->next->left;
            }
            // 分别对左右子树进行连接
            dfs(root->left);
            dfs(root->right);
        }
    }
};
```