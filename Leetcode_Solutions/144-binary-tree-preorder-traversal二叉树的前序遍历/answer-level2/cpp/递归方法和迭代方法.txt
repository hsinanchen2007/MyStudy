# 递归解法：

此解法比较简单，解释先访问 root 结点，然后用同样的方法去访问 root 结点的 left 结点，然后是 root 结点的 right 结点。注意这里使用了一个辅助函数 `pushNode()`, 测方法可以减少程序使用的内存：

```cpp
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        
        if (root) {
            pushNode(root, result);
        }
        
        return result;
    }

private:  
    void pushNode(TreeNode* root, vector<int> & vec) {
        if (root) {
            vec.push_back(root->val);
            pushNode(root->left, vec);
            pushNode(root->right, vec);
        }
    }
};
```

否则的话需要使用两个额外的 vector 去保存 left 结点、和 right 结点的返回结果，迭代层数越多，额外的 vector 越多，写出来的代码如下：
```cpp
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        
        if (root == NULL) {
            return result;
        }

        stack<TreeNode*> stackTree;
        TreeNode* tmp;

        stackTree.push(root);

        while (!stackTree.empty()) {
            tmp = stackTree.top();
            result.push_back(tmp->val);
            stackTree.pop();

            if (tmp->right != NULL)
                stackTree.push(tmp->right);

            if(tmp->left != NULL)
                stackTree.push(tmp->left);
        }        
        
        return result;
    }
};
```

# 迭代解法

此种解法需要使用一个  stack 进行辅助，首先将 root 结点 push 到 stack，然后就在一个 while 循环里去取 stack 的顶部，并将其保存。然后压栈 root 结点的** right 结点**，然后压栈 root 结点的 left 结点。**注意：这里先压栈 right 结点，是因为栈 LIFO 的特点**。直至 stack 为空。

```cpp
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        
        if (root == NULL) {
            return result;
        }

        stack<TreeNode*> stackTree;
        TreeNode* tmp;

        stackTree.push(root);

        while (!stackTree.empty()) {
            tmp = stackTree.top();
            result.push_back(tmp->val);
            stackTree.pop();

            if (tmp->right != NULL)
                stackTree.push(tmp->right);

            if(tmp->left != NULL)
                stackTree.push(tmp->left);
        }        
        
        return result;
    }
};
```


