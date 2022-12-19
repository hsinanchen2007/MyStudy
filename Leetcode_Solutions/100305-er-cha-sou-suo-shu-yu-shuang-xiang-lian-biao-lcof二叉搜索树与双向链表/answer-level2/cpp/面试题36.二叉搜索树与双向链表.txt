### 解题思路
核心思路：
    由二叉树变为双向链表，首先从根节点开始，调用中序遍历函数inorder，inorder的作用是将原二叉树变成了一个双向链表，且链表头存在全局变量head中，链表尾存在全局变量pre里，inorder返回后，将head前驱指向tail，tail后继指向head，就完成了题目要求的链表形式。
    下面详细说明inorder是如何做的：inorder是递归函数，递归出口是参数root为空，然后**在递归构建左子树和递归构建右子树的代码之间添加了一些指针操作**，第一步先检查pre是否为空，为空说明这是递归到了树的最下角（即第一次进入此处，pre还无初值），那么就找到了链表头，所以head=root（head指针指向当前位置，之后head再也不会变），pre不为空时，pre即为当前调用的前一次调用保留下的节点，也就是说pre里存着当前调用的root的前驱，所以pre->right=root，之后root->left=pre，根节点的前驱正确指向了pre，然后pre=root，结束该节点的递归
    此时可能有疑问，为什么此处节点root的后继还没有找到，就结束了呢？是因为我们把root保存在了pre里，到了下一个节点的inorder里，会把pre的right指向下一个节点，也就是说**inorder递归到每个节点所做的操作其实就三步，一是让上一节点的后继指向自己，二是自己的前驱指向上一节点，三是把自己存在pre里**）。

执行用时 :12 ms, 在所有 C++ 提交中击败了38.60%的用户
内存消耗 :7.6 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
    Node*head,*pre;
public:
    Node* treeToDoublyList(Node* root) {
        if(root==NULL)return NULL;
        inorder(root);
        head->left=pre;
        pre->right=head;
        return head;
    }
    void inorder(Node*root){
        if(root==NULL)return;
        inorder(root->left);
        if(pre==NULL)head=root;
        else pre->right=root;
        root->left=pre;
        pre=root;
        inorder(root->right);
    }
};
```