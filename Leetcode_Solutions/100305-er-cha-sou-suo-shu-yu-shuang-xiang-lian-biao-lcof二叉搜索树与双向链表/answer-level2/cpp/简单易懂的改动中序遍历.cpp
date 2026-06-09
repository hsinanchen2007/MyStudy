解题思路：二叉搜索树的特点是当前节点的左子树的值小于当前节点，当前节点的右子树的值大于当前节点。而题目要求排序一个循环双向链表。我们可以发现二叉搜索树的中序遍历刚好是由小到大排序的，因此可以通过中序遍历来解决这个问题。

那这个题和中序遍历有什么不一样的地方呢？我们很轻松地知道中序遍历的大概代码：

```cpp
void InorderTraverse(BiTree T)
{
	if(T=NULL)
		return;
	InOrderTraverse(T->lchild);     //中序遍历左子树，递归操作
	cout<<t->data;                  //显示结点数据，可以更改为其它操作；
	InOrderTraverse(T->rchild);     //最后中序遍历右子树，递归操作
}
```
我们这个题目和中序遍历的差别在哪呢？差别在于我们现在不是要输出中序遍历的节点值，而是要将中序遍历得到的每个节点值和其前面的中序遍历得到的值进行拼接；那么我们需要对上面的代码进行怎样的修改呢？

很简单，就是在cout<<t->data这个地方进行修改。我们要拼接两个节点，现在只知道了一个节点，那怎么办呢？这时候我们就需要一个参数来保存中序遍历中当前节点值的上一个节点值，这样我们就有了两个数据，这样就可以进行拼接了。

那怎么表达这一部分的操作呢？可以看看下面的代码：

```cpp
void InorderTraverse(BiTree T1， BiTree T2)  //T1是当前节点，T2是中序遍历的当前节点的上一个节点，默认初始为nullptr
{
	if(T=NULL)
		return;
	InOrderTraverse(T->lchild);      //中序遍历左子树，递归操作
	if(T2 != nullptr)                //如果当前节点的上一个中序遍历得到的节点不是nullptr
		T2->right = T1;              //上一个节点的右孩子就指向当前节点实现连接
	T1->left = T2;                   //当前节点的做孩子指向中序遍历的上一个节点实现连接
	T2 = T1;                         //因为当前节点操作完毕，需要递归下一个节点，对于下一个节点的前一个中序遍历的节点，我们可以知道就是当前节点，因此需要对T2的值进行修改，更新为最新的经过拼接的值，那就是T1
	InOrderTraverse(T->rchild);      //最后中序遍历右子树，递归操作
}
```
通过上面的代码，我们就把中序遍历中的输出节点值改为拼接当前节点和上一个节点了，这样就解决了这道题目了。

但要观察到题目要求得到的是循环双向链表。那我们怎么调整这一部分呢？
通过上面修改的中序遍历得到的是不循环的双向链表，T2是链表中的最后一个位置，这时候我们通过T2把不循环链表拼接起来呢？

同理，拼接数据，我们需要两个数据，现在有了最后位置的T2，怎么知道最开始链表的节点的位置Thead呢？我们可以通过T2的双向指针向前运动，直到找到最开始的点，这时候我们就有了两个数据，这样就可以将不循环链表拼接为循环链表了。

这一部分的功能实现主要如下：

```cpp
Node* Thead = T2;                                  //新定义一个节点，初始化为T2，我们不能动T2，因为T2最后要和Thead进行拼接
while(Thead!=nullptr && Thead->left!=nullptr)      //Thead不断向前运动
	Thead = Thead->left;                           //Thead的值不断更新

//得到Thead和T2之后，可以将其进行拼接
headNode->left = lastNode;
lastNode->right = headNode;
```

综上，整体C++代码如下：

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
        Node* lastNode = nullptr;              //该指针用于存储当前节点要拼接的上一个中序遍历的节点值，初始化为nullptr，因为对于第一个节点，其前一个中序遍历节点值没有。
        converNode(root,lastNode);             //进行中序遍历操作，这是关键部分
        Node* headNode = lastNode;             //该指针用于保存不循环双向链表中的最开始的节点
        while(headNode!=nullptr && headNode->left!=nullptr)  //寻找不循环双向链表中的起始位置
            headNode = headNode->left;
        if(headNode!=nullptr){                 //因为考虑到测试用例可能是[]，所以需要加一个判断条件
            headNode->left = lastNode;
            lastNode->right = headNode;
        }
        return headNode;                       //返回题目要求的节点值
    }
    void converNode(Node* root, Node* &prev){  //改动的中序遍历代码
        if(root==nullptr)
            return;
        if(root->left!=nullptr)                // 遍历左子树
            converNode(root->left,prev);

        if(prev!=nullptr)                      // 对当前节点和其对应的中序遍历的上一个节点进行拼接
            prev->right = root;
        root->left = prev;
        prev = root;

        if(root->right)                        // 遍历当前节点的左子树
            converNode(root->right,prev);
    }
};
```
时间复杂度为O(n)，空间复杂度为O(n)。

一开始其实一直想不懂，知道用中序遍历，但是中序遍历中间那一块怎么将数据拼接起来一直想不通，还是太菜了。其实道理很简单，我就中序遍历，这时候遍历得到的数据就是有序的，那我怎么将数据拼接起来呢，我只需要知道其前一个节点值，那我就可以进行拼接了啊，于是代码就很容易就出来了。这里和剑指offer不一样的地方在于，剑指offer里面没有要去是循环双向链表，只是要求是双向链表，其实整体上还是一样了，就是多了两行代码。