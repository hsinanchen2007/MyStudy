### 解题思路
使用的是二叉树的层次遍历，借助队列，每一层从左往右处理。


本代码可以原模原样处理这个题： 
[117. 填充每个节点的下一个右侧节点指针 II](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/)

这个题思路来自于题：
 [102. 二叉树的层次遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)

代码稍微更改一下，便是102题解。


### 代码

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        queue<Node*> q; //维护每一层的节点
        q.push(root); //第一层 只有根节点
        while(!q.empty()) //一个循环 处理一层
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                Node* node = q.front();
                q.pop();
                if(i == size -1) node->next = NULL; //NULL 本层右边没有节点了
                else node->next = q.front(); //每一层当前节点next 总是指向本层剩下队列的队首

                if(node->left != NULL) q.push(node->left); //当前节点是否有左子树，先左后右
                if(node->right != NULL) q.push(node->right); //当前节点是否有左子树
            }
        }
        
        return root;
    }
};
```

共同进步。