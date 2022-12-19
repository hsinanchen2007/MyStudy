### 分析
 运算规则和我们怎么做加法很像。我们做加法的时候加数和被加数的个位相加产生和的个位数，并且如果相加的结果大于10，需要向十位产生进位。同理十位、百位。
 此题中我们也可以采取这种方式。
（head1.val + head2.val + jinwei） % 10 就是结果中此位置的值。而新的进位为（head1.val + head2.val + jinwei） / 10 。
有两个地方是主要注意的。
 ** 1、可能会出现head1或者head2已经为null了的情况。**
 ** 2、最后head1和head2均为null以后，还要考虑jinwei如果不为0的情况，此时要加其加至链表末尾。**
 
 通过下图能很好的解释分析中介绍的内容。
![](https://pic.leetcode-cn.com/fc4ddac833d70dc7f8188c8a1846ab7d526eb8f7f64b1b59f626696f9ca8a781.png)
### 代码如下
```java
public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if (l1 == null) {
            return l2;
        }
        if (l2 == null) {
            return l1;
        }
        int jinwei = 0;
        ListNode res = new ListNode(-1);
        ListNode tmp = res;
        while (l1 != null && l2 != null) {
            int sum = l1.val + l2.val + jinwei;
            res.next = new ListNode(sum % 10);
            res = res.next;
            jinwei = sum / 10;
            l1 = l1.next;
            l2 = l2.next;

        }
        while (l1 != null) {
            int sum = l1.val + jinwei;
            res.next = new ListNode((sum) % 10);
            res = res.next;
            jinwei = sum / 10;
            l1 = l1.next;

        }
        while (l2 != null) {
            int sum = l2.val + jinwei;
            res.next = new ListNode((sum) % 10);
            res = res.next;
            jinwei = sum / 10;
            l2 = l2.next;

        }
        if (jinwei == 1) {
            res.next = new ListNode(1);
        }
        return tmp.next;
    }
```
下面这种代码看起来或许会更简洁一点。
```java
public ListNode addTwoNumbers2(ListNode l1, ListNode l2) {
        if (l1 == null) {
            return l2;
        }
        if (l2 == null) {
            return l1;
        }
        int jinwei = 0;
        ListNode res = new ListNode(-1);
        ListNode tmp = res;
        while (l1 != null || l2 != null) {
            int val1 = l1 == null ? 0 : l1.val;
            int val2 = l2 == null ? 0 : l2.val;
            int sum = val1 + val2 + jinwei;
            res.next = new ListNode(sum % 10);
            res = res.next;
            jinwei = sum / 10;
            if (l1 != null) {
                l1 = l1.next;
            }
            if (l2 != null) {
                l2 = l2.next;
            }
        }

        if (jinwei == 1) {
            res.next = new ListNode(1);
        }
        return tmp.next;
    }
```