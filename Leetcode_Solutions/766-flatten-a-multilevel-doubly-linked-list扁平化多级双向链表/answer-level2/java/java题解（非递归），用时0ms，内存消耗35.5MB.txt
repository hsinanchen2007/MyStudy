### 解题思路
![截图.PNG](https://pic.leetcode-cn.com/28431491d011f8ed4bfb539165d4b0dc1dbe0e722f9cde78231c1efb125efc38-%E6%88%AA%E5%9B%BE.PNG)

与二叉树扁平化类似，只是多了一个pre指针
1. 使用while循环，避免大量递归函数调用
2. 将结点的child结点移动next结点上，将next结点移动到child的尾部，注意要处理好父指针的指向

### 代码

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public Node prev;
    public Node next;
    public Node child;
};
*/
class Solution {
    public Node flatten(Node head) {
        Node p = head;
        while (p != null) {
            Node prev = p.prev;
            Node next = p.next;
            Node child = p.child;
            if (child != null) {
                //child结点移动到next
                child.prev = p;
                p.next = child;
                p.child = null;
                //找到child结点双向链表的最next结点
                Node lastNext = child;
                while (lastNext.next != null) {
                    lastNext = lastNext.next;
                }
                //将next结点放到最next结点的next
                if (next != null) {
                    lastNext.next = next;
                    next.prev = lastNext;
                }
            }
            p = p.next;
        }
        return head;
    }
}
```