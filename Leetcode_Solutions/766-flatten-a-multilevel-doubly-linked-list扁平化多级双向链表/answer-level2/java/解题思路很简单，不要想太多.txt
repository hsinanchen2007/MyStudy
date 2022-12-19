### 解题思路
前提条件是大家先看懂题目：二叉树展开为链表
[https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/]()
该题解参考：
[https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by--26/]()

然后：本题解法和二叉树一样，只需：
1、将child节点当做left节点，next节点当做right节点；
2、因为本题要求为双向链表，需要再添加一个prev指针，注意判空；

结束！是不是很简单！！！
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
        Node tmp = head;
        while(head != null){
            if(head.child != null){
                Node child = head.child;
                while(child.next != null){
                    child = child.next;
                }
                child.next = head.next;
                if(head.next != null){
                    head.next.prev = child;
                }
                head.next = head.child;
                head.next.prev = head;
                head.child = null;
            }
            head = head.next;
        }
        return tmp;
    }
}
```