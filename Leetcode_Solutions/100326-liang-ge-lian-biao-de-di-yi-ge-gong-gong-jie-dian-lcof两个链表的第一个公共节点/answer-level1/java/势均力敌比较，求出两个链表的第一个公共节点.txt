### 解题思路
求两个链表第一个共同节点
关键是长度相同才有可能是共同节点，所以先截掉链表长的部分，使两者长度相同再开始比较
    比如headA有10个节点和headB有6个节点，先将headA的前四个截去
两者长度相同后，同位置的用==比较即可
    （注意：不能比较val，因为共同节点指的是内存地址相同，并不是单单val相同）
### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB){
        int len1 = get_length(headA);
        int len2 = get_length(headB);

        int dist = len1 >= len2 ? (len1 - len2) : (len2 - len1);

        if (len1 >= len2){

            while (dist > 0){
                headA = headA.next;
                dist --;
            }

            while (headA != headB){
                headA = headA.next;
                headB = headB.next;
            }
            
            return headA;


        }else{
            while (dist > 0){
                headB = headB.next;
                dist --;
            }

            while (headA != headB){
                headA = headA.next;
                headB = headB.next;
            }

            return headA;

        }
    }

    public static int get_length(ListNode head){
        int len = 0;

        while (head != null){
            len ++;
            head = head.next;
        }

        return len;
    }
}
```