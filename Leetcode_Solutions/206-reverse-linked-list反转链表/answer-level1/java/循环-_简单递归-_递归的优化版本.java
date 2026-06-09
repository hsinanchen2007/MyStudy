1. 循环写法
三个指针，还是简单的。
```
public ListNode reverseList(ListNode head) {
        if(head==null||head.next==null) return head;

        ListNode p1=head,p2=head.next,p3=p2.next;
        head.next=null;
        while(p2!=null){
            p2.next=p1;
            p1=p2;
            p2=p3;
            if(p2!=null){
                p3=p2.next;
            }
        }
        return p1;
    }
```

2. 简单递归
递归的核心思想就是寻找子问题，链表翻转的子问题，就是去掉head结点之后剩余链表的翻转问题，因此基础思路就是先把head.next为首的链表翻转，然后找到该子链表的尾结点，把head接上。

该方法效率较低，因为每一次递归都要寻找子问题的尾结点，时间复杂度O(n^2)
    
```
public ListNode reverseList(ListNode head) {
        if (head == null || head.next == null) return head;
        //先翻转除head之外的子问题，返回子问题的新头结点
        ListNode newHead=reverseList(head.next);
        //寻找子问题翻转之后的最后一个结点，将head连接上去，并且设置head的next为null
        ListNode last=newHead;
        while(last.next!=null) last=last.next;
        last.next=head;
        head.next=null;

        return newHead;
    }
```

3. 递归写法优化版本

其实通过观察，可以发现不需要每一次递归都循环寻找尾结点，head.next恰好就是子问题的尾结点，所以循环遍历这一步完全可以省掉，优化后的代码如下：
```
public ListNode reverseList(ListNode head) {
        if (head == null || head.next == null) return head;
        //先翻转除head之外的子问题，返回子问题的新头结点
        ListNode newHead=reverseList(head.next);
        //寻找子问题翻转之后的最后一个结点，将head连接上去，并且设置head的next为null
        head.next.next=head;
        head.next=null;

        return newHead;
    }
```

