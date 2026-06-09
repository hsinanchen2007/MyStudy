#### 解题思路

通过题目我们发现，二叉树的镜像就是通过交换原二叉树中所有结点的左子树和右子树变换而成的，因此我们就需要编码来实现这种交换过程。



#### 递归

- 模型：二叉树的先序遍历（遍历二叉树的所有结点）
- 递归返回条件：当前结点为 NULL
- 实现操作：交换根结点的左右子树



#### 代码

```cpp
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        swap(root->left, root->right);
        mirrorTree(root->left);
        mirrorTree(root->right);
        return root;
    }
};
```



#### 栈模拟

- 模型：栈模拟二叉树的先序遍历
- 循环结束条件：栈为空
- 实现操作：交换栈顶结点的左右子树



#### 代码

```cpp
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            if (node == NULL) {
                continue;
            }
            swap(node->left, node->right);
            s.push(node->left); 
            s.push(node->right);
        }
        return root;
    }
};
```



#### 队列模拟

- 模型：使用队列模拟二叉树的层次遍历
- 循环结束条件：队列为空
- 实现操作：交换队首结点的左右子树



#### 代码

```cpp
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node == NULL) {
                continue;
            }
            swap(node->left, node->right);
            q.push(node->left);
            q.push(node->right);
        }
        return root;
    }
};
```



#### 最后

感谢您的观看！欢迎大家留言，一起讨论交流，共同进步。

至此，您已经掌握了返回二叉树镜像的三种实现方式，如果这篇文章对您有帮助，欢迎扫描下方二维码关注我的公众号“小小算法”，感谢您的支持！

![小小算法.png](https://pic.leetcode-cn.com/ecef5d3425d27258a1eb6a6229ac205033df84302ad4124308328351bdf56e86-%E5%AE%A3%E4%BC%A0%E5%9B%BE2.png)