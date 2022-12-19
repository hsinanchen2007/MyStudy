# 对于一个链表而言：下面的情况都可以使用快慢指针法：
    1.查询链表的中间节点：当快指针走到末尾的时候，慢指针正好处于中间的位置，
    2.判断一个链表有没有环：当快指针走完两圈之后，慢指针正好走一圈。

针对这道判断是不是回文字符串：
## 方法一：
利用ArrayList使其具有随机访问的能力，我们就可以利用下边的方式进行判断是不是回文，一个下标指向开始位置，一个下标指向结束位置。这种方法的时间复杂度为O(N)，空间复杂度为：O(N)。
## 方法二：
* 利用快慢指针法。（有一个副作用：将会改变原始链表。）
#### 思想：
* 回文字符串：就是首尾对应位置的字符一样，换言之：如果从中间位置开始，一个指针向前，一个指针向后，这两个指针对应的字符也要相同。
#### 步骤：
* 第一步：找到中间节点。
* 第二步：定义两个指针，分别指向中间节点。然后一个指针向前，一个指针向后。
* 然而，单向链表只有向后的指针，向后走的指针没有问题，向前走的指针怎么向前操作？
* 我们在查找中间节点的时候，我们可以对前面一部分的指针进行翻转。这样的话，向前操作，就会变成向后操作。即：每遍历一个元素，我们将它放入起始位置。
#### 代码如下：
```
class Solution {
    public boolean isPalindrome(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        head = null;
        while (fast != null && fast.next != null) {
            //这个必须放在第一行，不然下面进行链表反转，fast就不能正常指向了
            fast = fast.next.next;
            //进项反转
            ListNode next = slow.next;
            slow.next = head;
            head = slow;
            slow = next;
        }
        if (fast != null) {
            slow = slow.next;
        }
        fast = slow;
        slow = head;
        while(slow != null) {
            if (slow.val != fast.val) {
                return false;
            }
            slow = slow.next;
            fast = fast.next;
        }
        return true;
    }
}
```
