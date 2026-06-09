### 解题思路
做法就是将先创建一个节点然后遍历所给出的节点将遍历到的节点逆序插入到创建的节点后面，最后的返回值是创建的节点的next。



### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        //遍历一下链表，然后倒序插入就可以了
        //先创建一个头节点返回值为头节点的下一个节点
        ListNode result = new ListNode(-1);
        ListNode temp =head;
        while(temp!=null){
            //先将下一个节点保存起来便于之后使用，然后将
            ListNode p = temp;
            temp = temp.next;//保存下一个链表接下来的链表
            p.next = result.next;//将此次循环到的节点倒着插入到result节点后面
            result.next = p;//分为两步，第一就是上面的
        }
        return result.next;
    }
}
```