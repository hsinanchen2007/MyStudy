# 解题思路：

对链表画个简图，不难发现存在一个“伪环”。（一字丑，二人懒，就不上图了）
1. 将链表的尾部指向头部，形成了一个环，即 `list.tail.next = list.head`
1. 将倒数第二个节点指向`NULL`，变成新的链表尾，`list.tail.pre.next = null` 。同时意味着原本的尾变成了新的头。

如果`k`很小（小于链表的长度），将上面2步重复k次即可。
但如果`k`很大，循环起来对内存消耗很大，也没必要。要知道，对链表右移一个链表的长度，相当于没有移动。所以，只要重复 `k%list.size` 次即可    

#
  
>注意：对k要取模。
第一次的代码我没有取模。执行代码可以通过，但提交就失败了，它的测试案例`k=20000` 。
一种挫败感油然而生：好不容易写出的解法，不说击败百分之多少了，居然都不能通过。
随意翻了一下题解，看到@leetcode（这里@不好用。。）提到`%`，恍然醒悟。在自己的代码里加上取模，提交成功了，结果还行。

# 代码

```
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null) {
            return head;
        }

        // 计算列表的长度
        // 是为了下面的for循环取模
        int len = 0;
        ListNode pointer = head; // 移动指针
        ListNode pre = null; // 当前指针（pointer）的前一个节点

        while (pointer != null) {
            len ++;
            pointer = pointer.next;
        }

        pointer = head; // 指针重新指向表头

        // 如果不取模，k很大时将超时
        for (int i = 0; i < k % len; i++) {

            // 将指针移到最后一个节点
            while (pointer.next != null) {
                pre = pointer;
                pointer = pointer.next;
            }

            // 首尾相连，形成伪环
            pointer.next = head;
            // 原先的列表尾部变成列表头
            head = pointer;
            // 倒数第二个节点变成列表尾部，指向null
            pre.next = null;
        }

        return pointer;
    }
```
