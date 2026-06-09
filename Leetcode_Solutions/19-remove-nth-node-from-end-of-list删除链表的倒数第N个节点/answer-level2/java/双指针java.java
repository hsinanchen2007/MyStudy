### 解析
本题是一个经典的双指针问题。解题思路如下。
    1、新建一个新链表res，并让res的next指针指向head。并新建fast和slow，他们均指向res。
    2、将fast往后移n个距离。
    3、同时移动fast和slow，直到fast.next == null为止。
    4、此时slow为倒数第n个节点的前一个节点。slow.next = slow.next.next就可以将倒数第n个节点移除。
### 代码
```java
public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode res = new ListNode(-1);
        res.next = head;
        ListNode fast = res;
        ListNode slow = res;

        while (n-- > 0){
            fast = fast.next;
        }
        //为了找到要删除的节点的前一个节点，所以此处让fast.next!=null
        while (fast.next != null){
            fast = fast.next;
            slow = slow.next;
        }
        //此时slow为倒数第n个节点的前一个节点。
        slow.next = slow.next.next;
        return res.next;

    }
```
本人建了个公众号用于刷题交流，欢迎关注：
![qrcode_for_gh_8eedbc428c9a_258(1).jpg](https://pic.leetcode-cn.com/e5f794b173fbe256a541447fc7ff8e6eb031774890bdfdb48ca3c7866dc81dc2-qrcode_for_gh_8eedbc428c9a_258\(1\).jpg)
