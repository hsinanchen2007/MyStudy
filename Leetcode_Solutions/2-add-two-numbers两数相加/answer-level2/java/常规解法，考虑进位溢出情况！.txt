### 解题思路
面试遇到过这个题目，主要考虑的点是3个：
1.两个链表长度不一样，以哪个为准，怎么判断什么时候停止？
2.如果在最后一位加和>10，导致进位，这位怎么保存？
3.怎么返回最终的结果，链表怎么维护？

解析：
针对1:两个只要有一个还没走到尾部，循环就不能停止，所以循环条件为：while(l1!=null || l2!=null)。所以只要还在while循环里面就有三种情况，第一种，两个都没走到尾部，则当前位加和等于上一位的进位（high）+两个链表的节点值；第二种，第一个没走到尾部（第二个走到尾部了），则当前位加和等于上一位的进位（high）+第一个链表当前节点的值；第三种，第二个没走到尾部（第一个走到尾部了），则当前位加和等于上一位的进位（high）+第二个链表当前节点的值。
针对2:最后在整个循环结束后算下进位（high）是否大于0，大于说明溢出，则要新建一个node。
针对3:首先建立一个头节点，用于记录链表入口。同时需要一个temp指针可以让链表不断向后移动，指向新的节点，从而形成链表。

### 代码

```java（常规解法，不用判断两个链表的长短关系，直接开搞，if情况覆盖所有可能情况）
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        // 低位
        int lower = 0;
        // 高位
        int high = 0;
        // 当前和
        int cur = 0;
        ListNode head = new ListNode(0);
        ListNode temp  = head;     
        // 只要有一个没遍历到尾部，表示还没有加完   
        while(l1!=null || l2!=null){
            // 两个都没遍历到尾部
            if(l1!=null && l2!=null){
                cur=high+l1.val+l2.val;
                l1=l1.next;
                l2 = l2.next;
            }
            // l1还没遍历到尾部（l2已经遍历到尾部了）
            else if(l1!=null){
                cur=high+l1.val;
                l1 = l1.next;
            }
             // l2还没遍历到尾部（l1已经遍历到尾部了）
            else{
                cur=high+l2.val;
                l2=l2.next;
            }
            lower = cur%10;
            high = cur/10;
            // 新建node
            ListNode node = new ListNode(lower);
            temp.next = node;
            temp = node;
        }
        // 如果进位>0，表示最后加和溢出了一个高位，需要新建node存起来
        if(high>0){
            ListNode node = new ListNode(high);
            temp.next = node;
        }
        // 返回头节点
        return head.next;
    }
}
```