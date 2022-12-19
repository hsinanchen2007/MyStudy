递归主要的思路就是： 对于当前节点的下一个节点做递归， 返回的是 已经反转好的链表的头节点 或 尾节点， 然后将当前节点挂在最后；

返回尾节点的解法： 0ms
![31TBODCNSXU@\[5M1}F{K1)N.png](https://pic.leetcode-cn.com/d50c8c94c98a29b71e57dbf7ead0331e09ca23b4cb948dd7094d55ceb5ff5fb3-31TBODCNSXU@%5B5M1%7DF%7BK1\)N.png)
```
public static ListNode newHead = null;     //将头节点设置为全局变量，这样每次返回尾节点就不用顾及之前的节点了
    public ListNode reverseList(ListNode head) {   // 0ms 100%
        newHead = null;
        solve(head);
        return newHead;
    }
    public ListNode solve(ListNode temp){
        if (temp == null)    //如果是null 之间返回null
            return temp;
        if (temp.next == null){   //如果next是null，则说明当前节点是反转后的头节点
            newHead = temp;
            return temp;  // 当然此时链表中只有一个节点，所以头节点亦是尾节点
        }

        ListNode lastNode = solve(temp.next);   //将当前节点添加到尾节点后面
        temp.next = null;     //当前节点的next清空
        lastNode.next = temp;
        return temp;    //此时已经添加上去，当前节点便是尾节点，返回即可
    }
```


返回头节点的解法 ：  70ms  性能较差，不做过多解释
```
public ListNode reverseList(ListNode head) {  //70ms
        if (head == null)
            return null;
        if (head.next == null)
            return head;

        ListNode temp = reverseList(head.next);
        ListNode newHead = temp;
        for (;temp.next!=null; temp = temp.next);

        temp.next = head;
        head.next = null;
        return newHead;
    }
```
