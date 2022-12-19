### 解题思路
解法一：广度优先搜索，也就是逐层遍历二叉树
空间复杂度：需要使用队列，复杂度为O(N), N为二叉树的节点数目
###
```
class Solution {
public:
    Node* connect(Node* root)
    {
        queue<Node*> connectQueue;
        if (root == NULL || root->left == NULL) {
            return root;
        }

        connectQueue.push(root);
        while (connectQueue.empty() != true) {
            int size = connectQueue.size();
            for (int i = 0; i < size; i++) {
                Node* cur = connectQueue.front();
                if (cur->left != NULL) {
                    cur->left->next = cur->right;
                    connectQueue.push(cur->left);

                    if (cur->next != NULL) {
                        cur->right->next = cur->next->left;
                    }
                    connectQueue.push(cur->right);
                }

                connectQueue.pop();
            }
        }

        return root;
    }
};
```

###
解法二：递归，对左右子树递归调用即可，对比解法一，代码简洁直观，且不占用额外空间（按照提议，忽略递归调用栈的空间）
1、递归终止条件：空节点或者叶子节点，则递归停止
2、自上而下进行递归，先处理本节点的子节点的下一个右侧节点，然后再对左右子节点分别递归

执行用时 :24 ms, 在所有 cpp 提交中击败了98.64%的用户
内存消耗 :19.2 MB, 在所有 cpp 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
    Node* connect(Node* root)
    {
        if (root == NULL || root->left == NULL) {
            return root;
        }

        root->left->next = root->right;
        if (root->next != NULL) {
            root->right->next = root->next->left;
        }

        (void)connect(root->left);
        (void)connect(root->right);

        return root;
    }
};
```