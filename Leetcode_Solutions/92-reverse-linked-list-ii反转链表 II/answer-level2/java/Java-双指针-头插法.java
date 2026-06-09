思路：1、我们定义两个指针，分别称之为g(guard 守卫)和p(point)。
我们首先根据方法的参数m确定g和p的位置。将g移动到第一个要反转的节点的前面，将p移动到第一个要反转的节点的位置上。我们以m=2，n=4为例。

![1.png](https://pic.leetcode-cn.com/5389db651086bd4bcd42dd5c4552f180b553a9b204cfc1013523dfe09beac382-1.png)


2、将p后面的元素删除，然后添加到g的后面。也即头插法。
![2.png](https://pic.leetcode-cn.com/db22bdb60035e45f8c354b3f45f2a844260d6cafcf81528d2c4f1b51e484fb45-2.png)

3、根据m和n重复步骤（2）
4、返回dummyHead.next

``` java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {
        ListNode dummyHead = new ListNode(0);
        dummyHead.next = head;

        ListNode g = dummyHead;
        ListNode p = dummyHead.next;

        int step = 0;
        while (step < m - 1) {
            g = g.next; p = p.next;
            step ++;
        }

        for (int i = 0; i < n - m; i++) {
            ListNode removed = p.next;
            p.next = p.next.next;

            removed.next = g.next;
            g.next = removed;
        }

        return dummyHead.next;
    }
}
```

