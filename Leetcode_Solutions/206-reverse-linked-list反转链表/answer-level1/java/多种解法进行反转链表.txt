反转一个单链表，此题为面试高频题。

示例:
```
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
```

## 解法一：递归
假设列表的其余部分已经被反转，现在我该如何反转它前面的部分？

```java
    public ListNode reverseList(ListNode head) {
        //终止条件
        if(head == null || head.next == null){
            return head;
        }

        //1. 找到最后一个节点
        ListNode p = reverseList(head.next);
        //2. 本层要做的事情，就是使得下一个节点指向它自己。
        head.next.next = head;
        head.next = null;

        return p;
    }
```

## 解法二:另一种递归解法
对于链表中的每一个元素，只需将当前节点的 next 指针改为指向前一个元素，就可完成链表反转。需要保存这个元素的上一个元素lastNode，以及当前指针所在的节点。
```java
    public ListNode reverseList(ListNode head) {
        return reverseList(null,head);
    }
    public ListNode reverseList(ListNode lastNode, ListNode curr) {
        if(curr == null){
            return lastNode;
        }
        ListNode next = curr.next;
        curr.next = lastNode;
        return reverseList(curr, next);        
    }
```

## 解法三：循环
解法二的循环写法。

```java
    public ListNode reverseList(ListNode head) {

        ListNode pre = null;
        ListNode curr = head;
        ListNode temp;

        while (curr != null) {
            temp = curr.next;
            curr.next = pre;
            pre = curr;
            curr = temp;
        }

        return pre;
    }
```

原文地址：[反转链表](https://blog.csdn.net/wangdong5678999/article/details/103448738)