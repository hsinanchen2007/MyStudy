## 前置知识

> **二叉搜索树**
>
> 二叉搜索树又叫二叉排序树，具有如下性质：根节点比左节点的值大，比右节点的值小；其左右子树也都是二叉搜索树。根据该性质可以知道，二叉搜索树可以用来排序，一直沿着左子树搜索可以得到最小值，一直沿着右子树搜索可以得到最大值；

## 题目描述

>输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。
>
>特别地，我们希望可以就地完成转换操作。当转化完成以后，树中节点的左指针需要指向前驱，树中节点的右指针需要指向后继。还需要返回链表中的第一个节点的指针。















## 思路

### 递归法

> 递归的想法是：把左子树当作一个已经排序好的链表，右子树也当作一个排序好的链表，然后接下来的问题就是如何将根节点和左右两个排序好的链表组合起来，这一步非常简单

```java
public Node treeToDoublyList(Node root) {
        if(root == null){
            return null;
        }
        if(root.left == null && root.right == null){
            root.left = root;                 //这一步是必须的
            root.right = root;                //这一步是必须的，即使返回一个节点，我们也要把这个节点看成一个双向链表，否											  //则程序会抛出NullPointerException
            return root;
        }
        Node leftHead =  treeToDoublyList(root.left);
        Node rightHead = treeToDoublyList(root.right);
        if(leftHead != null && rightHead != null){
            root.right = rightHead;
            root.left = leftHead.left;
            leftHead.left = rightHead.left;
            rightHead.left = root;
            root.left.right = root;
            leftHead.left.right = leftHead;
            return leftHead;
        }else if(leftHead != null && rightHead == null){
            root.left = leftHead.left;
            root.right = leftHead;
            leftHead.left = root;
            root.left.right = root;
            return leftHead;
        }else{
            root.right = rightHead;
            root.left = rightHead.left;
            root.left.right = root;
            rightHead.left = root;
            return root;
        }
       
    }
```

