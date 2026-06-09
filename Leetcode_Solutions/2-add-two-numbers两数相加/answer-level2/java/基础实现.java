### 解题思路
刚刚看到题目，想起了cpu计算二进制加法运算方式，每次都是将需要相加的两个数加上前一位的进位作为下一次加法运算的输入位。接下来就是代码具体实现了，因为需要遍历完链表，所以时间复杂度位O(max(n,m)),内存方面直接复用链表存储，考虑最后如果有进位的话需要new一个新节点，空间复杂度O(1),具体算法实现如下

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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {

        int result = 0;
        int jinwei = 0;

        ListNode head = l1;
        ListNode tail = l1 ;

        while(null!=l1 || null!=l2){

            if(null!=l1&&null!=l2){
                result = jinwei + l1.val + l2.val;
                l1.val = result%10;
                jinwei = result/10;
                tail = l1;
                l1 = l1.next;
                l2 = l2.next;
            }else if(null!=l1){
                tail = l1;
                result = jinwei+l1.val;
                l1.val = result%10;
                jinwei = result/10;
                l1 = l1.next;
            }else if(null!=l2){
                result = jinwei+l2.val;
                l2.val = result%10;
                jinwei = result/10;
                tail.next = l2;
                tail  = l2;
                l2 = l2.next;
            }
            
        }
        if(jinwei!=0){
            ListNode node = new ListNode(jinwei);
            tail.next = node ;
        }
        return head ;
    }
}
```