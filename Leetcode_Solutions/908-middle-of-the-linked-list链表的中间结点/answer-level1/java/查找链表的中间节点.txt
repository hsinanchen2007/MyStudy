### 解题思路
此处撰写解题思路

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
    public ListNode middleNode(ListNode head) {
           // 首先获取 链表的长度
              int size = 0;
              ListNode tmp = head;
              while(head != null){
                     size++;
                     head =head.next;
              }
              // 得到中间值 
              int mid = size /2 ;
              while(mid != 0){
                     tmp = tmp.next;
                     mid--;       
              }
       return  tmp;
  }
}

```