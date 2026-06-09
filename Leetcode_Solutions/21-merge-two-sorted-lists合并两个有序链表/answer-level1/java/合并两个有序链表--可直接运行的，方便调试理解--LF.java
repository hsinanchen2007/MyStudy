链表定义部分：
```
package ZJM_21_合并两个有序链表;

public class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}

```
实例代码：
```
package ZJM_21_合并两个有序链表;

public class Main {
    public static void main(String[] args) {
//        1->2->4, 1->3->4
        ListNode l1 = new ListNode(1);
        ListNode l2 = new ListNode(2);
        ListNode l3 = new ListNode(4);
        ListNode m1 = new ListNode(1);
        ListNode m2 = new ListNode(3);
        ListNode m3 = new ListNode(4);

        l1.next = l2;
        l2.next = l3;
        l3.next = null;

        m1.next = m2;
        m2.next = m3;
        m3.next = null;

        Solution solution = new Solution();
        ListNode result = solution.mergeTwoLists(l1,m1);

        while (result!=null){
            System.out.print(result.val+" ");
            result = result.next;
        }
    }
}

/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode l =new ListNode(-1);

//        ListNode temp2 =new ListNode(-1);
//        ListNode temp3 =new ListNode(-1);
//        ListNode temp4 =new ListNode(-1);
//        ListNode temp5 =new ListNode(-1);
//        ListNode temp6 =new ListNode(-1);
//
//        temp.next=temp2;
//        temp2.next=temp3;
//        temp3.next=temp4;
//        temp4.next=temp5;
//        temp5.next=temp;
//        temp6.next=null;

        ListNode temp = l;

//        while(l1.next!=null&&l2.next!=null){
        while(l1!=null&&l2!=null){
            if(l1.val>l2.val){
//                temp.val = l2.val;
//                l2=l2.next;
//                temp = temp.next;
                temp.next = l2;
                l2=l2.next;
            }
            else{
//                temp.val = l1.val;
//                l1=l1.next;
//                temp = temp.next;
                temp.next = l1;
                l1=l1.next;
            }
            temp = temp.next;
        }

        if(l1==null){
            temp.next = l2;
        }
        else {
            temp.next = l1;
        }

        return l.next;
    }
}

/**
 * 本题主要考察的是链表部分的掌握，在函数中新建立一个链表节点，通过这个链表节点对两条链表进行比较后，next有序排列
 */

```
