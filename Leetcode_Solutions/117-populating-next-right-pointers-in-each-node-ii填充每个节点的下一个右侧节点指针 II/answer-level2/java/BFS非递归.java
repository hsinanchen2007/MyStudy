![微信图片_20191227123848.png](https://pic.leetcode-cn.com/21602fec66256fdb3e7e5ac1b7cc7c2d2a0aadf7030d4e81b21fd5c990208712-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20191227123848.png)

### 解题思路
```
             1
           /   \
          2 --> 3
         / \   / \ 
        4-->5-6-->7
       /           \ 
      8             9    
```
我们以第三层和第四层为例分析，当我们在第三层准备逐个遍历节点时，我们就要确定下一层的first节点，并将下一层的所有节点依次链接起来。比如：我们cur节点指向4，确定first节点为8，但是因为4无右孩子且5,6均无孩子节点，所以造成了cur节点与下一层节点链接脱节，所以我们需引入tail节点表示下一层的链表的尾节点
该题是前面一道题的升级版，不过前一道题中的树是完全二叉树，只需要设置first和cur两个节点即可，first节点表示每一层的第一个节点，cur表示每一层中当前节点，使用while循环嵌套即可完成；但这道题由于不具备完全二叉树的性质，所以下一层的first节点不能直接得到，需要通过cur节点去找到;考虑以上情况，引入first、cur、tail三个节点

### 代码

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
    public Node connect(Node root) {
        if(root == null) return null;
        Node first = root;
        Node cur = root;
        while(first != null){  //如果当前层不存在first节点,说明遍历完成
            first = null;  //在每次进入一层后,清空first，方便寻找下一层first节点
            Node tail = new Node();   //声明tail
            while(cur != null){
                if(cur.left != null){
                    if(first == null) first = cur.left;  //first节点仅赋值一次
                    tail.next = cur.left;
                    tail = tail.next;
                    if(cur.right != null){
                        tail.next = cur.right;
                        tail = pre.next;
                    }
                }else if(cur.right != null){
                    if(first == null) first = cur.right; //first节点仅赋值一次
                    tail.next = cur.right;
                    tail = tail.next;
                }
                cur = cur.next;
            }
            cur = first;  //从下一层first节点开始寻找
        }
        return root;
    }
}
```