### 解题思路
其实自己大概，就能想清楚为啥了，
1. head就是一个链表，并不是所谓的头结点，在链表下，指向头结点就是指向了整个链表。
2. 在遍历的过程中，我只是定义了一个指针，指针在运行的过程，只是在修改链表中的元素，但是在最后返回时，还是需要返回链表本身。

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
    public ListNode deleteDuplicates(ListNode head) {
        ListNode cur=head;
        while(cur!=null&&cur.next!=null){  //注意是与&&&&
            if(cur.val==cur.next.val){
                cur.next=cur.next.next;  //该节点和下个节点值相同，把下下个节点赋给下节点
            }else{
                cur=cur.next;//不相同，就是正常的链表操作，下一个
            }
        }
        return head;     //返回head?为啥
        //其实自己大概，就能想清楚为啥了，head就是一个链表，并不是所谓的头结点
        //在链表下，指向头结点就是指向了整个链表
        //在遍历的过程中，我只是定义了一个指针，指针在运行的过程，只是在修改链表中的元素
        //但是在最后返回时，还是需要返回链表本身
    }
}
```