### 解题思路
1、将链表翻转，同时记录链表长度
2、遍历翻转后的链表，输出节点值到数组
这里遍历了两遍链表，时间复杂度为O(n)，空间复杂度为O(1)

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
    public int[] reversePrint(ListNode head) {
        // 翻转链表，同时记录链表长度
        if(head==null){
            return new int[0];
        }
        int length=0;
        // e为原链表中的某个节点，开始为头结点
        ListNode e=head;
        // next为原链表中e指向的下一节点
        ListNode next;
        // previous为链表翻转后e需要指向的下一节点，头结点变为尾节点之后，next指向null
        ListNode previous=null;

        // 翻转链表
        while(e!=null){
            next=e.next;
            e.next=previous;
            previous=e;
            e=next;
            length++;
        }
        // 循环执行后，翻转完成，且previous为翻转后链表的头节点
        // 遍历翻转后的链表，将各节点的值输出到int数组
        int[] array=new int[length];
        int index=0;
        e=previous;
        while(e!=null){
            array[index]=e.val;
            e=e.next;
            index++;
        }
        return array;
    }
}
```

另一种更方便的做法，不翻转链表，同样是遍历两次链表。
第一次先获得链表长度，第二次遍历倒序插入数组
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
    public int[] reversePrint(ListNode head) {
        if(head==null){
            return new int[0];
        }
        // 获取链表长度
        int length=0;
        ListNode e=head;
        while(e!=null){
            length++;
            e=e.next;
        }
        // 将各节点的值以倒序方式输出到int数组
        int[] array=new int[length];
        int index=length-1;
        e=head;
        while(e!=null){
            array[index]=e.val;
            e=e.next;
            index--;
        }
        return array;
    }
}
```