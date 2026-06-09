### 解题思路
首先构造一个merge方法，归并排序两个子节点；
采用自顶向上或者自底向上完成排序。

### 自底向上
需要使用队列；
依次将两个，四个...节点归并排序，直到队列为空。

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
    public ListNode sortList(ListNode head) {

        //初始化
        ListNode cur;
        Deque<ListNode> queue = new LinkedList<>();
        for( ; head != null; head = cur){
            cur = head.next; head.next = null; queue.offer(head);
        }

        //排序并循环添加
        head = queue.poll();
        while(!queue.isEmpty()){
            queue.offer(head); head = merge(queue.poll(),queue.poll());
        }
        return head;
    }

    //归并操作
    ListNode merge(ListNode a, ListNode b){
        ListNode c = new ListNode(0);
        ListNode head = c;
        while(a != null && b != null){
            if (a.val < b.val){
               c.next = a; c = a; a = a.next; 
            }else{
                c.next = b; c = b; b = b.next;
            }
        }
        c.next = (a == null) ? b : a;
        return head.next;
    }
}
```

### 自顶向下
使用一个技巧，一个指针走一步，另一个走两步，达到中分链表的作用；
每次先中分链表，在分别归并排序。

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
    public ListNode sortList(ListNode head) {

        //寻找链表中间节点
        ListNode a,b;
        if(head == null || head.next == null) return head;
        a = head; b = head.next;
        while(b != null && b.next != null){
            head = head.next; b = b.next.next;
        }
        b = head.next; head.next = null;

        //分治，递归调用
        return merge(sortList(a),sortList(b));
    }

    //归并操作
    ListNode merge(ListNode a, ListNode b){
        ListNode c = new ListNode(0);
        ListNode head = c;
        while(a != null && b != null){
            if (a.val < b.val){
               c.next = a; c = a; a = a.next;
            }else{
                c.next = b; c = b; b = b.next;
            }
        }
        c.next = (a == null) ? b : a;
        return head.next;
    }
}
```

参考：《算法：C语言实现》