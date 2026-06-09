### 解题思路
思路：用一个新的链表存储我们的结果。
每次，把两个节点反转，存入新的链表。

具体步骤：
把当前节点的下一个节点，指向为当前节点的前一个节点。然后把这一步的链表存一下。

所以步骤可以变为：
定义空节点。prev。意义为current的前一个节点。第一次循环时，是默认值null。
1、先把当前节点current后面的节点next，放在一边存起来（nextTemp），
2、然后当前节点current的next指向前一个节点prev。当前节点反转完毕。
3、把反转后的当前节点存储，prev这个指针用完了（2中用了一次就他就没有用了），所以可以吧current存到prev里，正好作为下次循环的前一个节点。
4、当前节点current未反转前的next作为current，参与下次循环。即：把nextTemp作为current。

解释一下3：每次循环之后，反转后的链表的头结点，就是未反转之前的前一个节点。
假设链表为：1——》2——》3——》4——》null
当前节点为1时。current，1，的next指向前一个节点。存入l1中。l1就等于1——》null。
current=nextTemp之后，就变成了：
2——》3——》4——》null。
l1是1-》null。l1的头结点是current的前一个节点。

第二次循环后，current是：
3-》4——》5——》null
l1是：
2-》1-》null


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
    public ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode cur = head;
        while(cur!=null){
           ListNode nextTemp = cur.next;
           cur.next = prev;
           prev = cur;
           cur = nextTemp;
        }
        return prev;
    }
}
```