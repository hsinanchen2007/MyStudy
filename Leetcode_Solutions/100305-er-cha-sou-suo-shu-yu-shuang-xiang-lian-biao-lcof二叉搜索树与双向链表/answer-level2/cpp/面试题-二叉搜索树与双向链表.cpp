### 解题思路
- 我觉得首先要了解，树的前中后三种遍历方式，以及其递归代码。
- 中序遍历正好能按照从小到大的顺序遍历二叉搜索树。
- 按照中序遍历，先1再2再3，假设我们成功的将左子树变为一个排好序的链表，并且链表的最后一个结点是当前的最大值。那么只要把3和根节点4接上，然后继续按照中序去遍历右子树。至于怎么转化左子树和右子树，那自然想到递归了。
```
        4
      /   \ 
     2     7
    / \   / \
   1   3 5   6
```


```cpp
//前序：
void PreOrderTraverse(BiTree T, int level)
{
    if (T == NULL)
        return;

/*此处表示对遍历的树结点进行的操作，根据你自己的要求进行操作，这里只是输出了结点的数据*/
    //operation1(T->data);
    operation2(T->data, level); //输出了层数

    PreOrderTraverse(T->lchild, level + 1);
    PreOrderTraverse(T->rchild, level + 1);
}

//递归方式中序遍历二叉树

void InOrderTraverse(BiTree T,int level)
{
if(T==NULL)
return;
InOrderTraverse(T->lchild,level+1);

//operation1(T->data);
operation2(T->data, level); //输出了层数

InOrderTraverse(T->rchild,level+1);
}

//递归方式后序遍历二叉树

void PostOrderTraverse(BiTree T,int level)
{
if(T==NULL)
return;
PostOrderTraverse(T->lchild,level+1);
PostOrderTraverse(T->rchild,level+1);

//operation1(T->data);
operation2(T->data, level); //输出了层数
}
```


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
public:
    Node* treeToDoublyList(Node* root) {
        if(root == NULL)
            return NULL;
        Node* head = NULL;
        Node* pre = NULL;
        helper(root,head,pre);
        head->left = pre;
        pre->right = head;
        return head;
    }
void helper(Node* root,Node* &head,Node* &pre)
{
    if(root == NULL)
        return;
    helper(root->left,head,pre);
    if(head == NULL)
    {
        head = root;
        pre = root;
    }
    else
    {
        root->left = pre;
        pre->right = root;
        pre = root;
    }
    helper(root->right,head,pre);
}

};



















```