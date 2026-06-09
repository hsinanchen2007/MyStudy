### 解题思路
此处撰写解题思路
交换相邻：**head.next复制为后期，并将head.next.next=head;//反向；return head.next;）**
swapPairs（head）：交换以head为头结点的链表中的相邻节点。
![无标题.png](https://pic.leetcode-cn.com/686a9e89530d9725d812a54b619f0c9637b6d8191013c2cfc43a851287775e13-%E6%97%A0%E6%A0%87%E9%A2%98.png)

![Snipaste_2020-03-23_11-56-06.png](https://pic.leetcode-cn.com/290bf374fceb9d8aa3ee097174a0638617d92ae46672c3d6f477e04ef98a8729-Snipaste_2020-03-23_11-56-06.png)

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
    public ListNode swapPairs(ListNode head) {//交换以head为头结点的链表中的相邻节点。
        if(head==null||head.next==null){
            return head;
        }
        ListNode next=head.next;
        head.next=swapPairs(next.next);
        next.next=head;
        return next;

    }
}
```