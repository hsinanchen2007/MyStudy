### 解题思路
这个思路相对来说比较简单，但是带来的时间复杂度会更高，并不是最优的解决方案，因为将逆向变成正向查找会更加耗时。这里重在分享思路~大家了解一下即可：
由于题目给出的是倒数第k个节点，按照常理来说，正向推导更加便捷，因此先设倒数第k个节点相当于正数第i个节点。运用数学逻辑，可得出：i=链表长度length-k+1。所以接下来的步骤归纳如下：
**1.求链表长度length：**
先设置一个记录长度数据的变量，然后遍历列表，遍历一个数据就加一个长度即可；
**2.根据求长度的原理，亦可判断当下的正向索引是否等于i：**
设置一个记录当前索引（从1开始）的变量j,只要j<i，则说明还未查询到第i个节点处，head指向head.next，索引j加1，继续判断并循环。直到j=i时，说明j已经找到节点i，此时head也已经指向i，直接return head即可。

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
    public ListNode getKthFromEnd(ListNode head, int k) {
        int length = 0;
        if (head == null) {return head;}
        ListNode tmp = head;
        while (tmp != null) {
            length++;
            tmp = tmp.next;
        }
        int i = length - k + 1;
        int j = 1;
        while (j < i) {
            head = head.next;
            j++;
        }
        return head;
    }
}
```