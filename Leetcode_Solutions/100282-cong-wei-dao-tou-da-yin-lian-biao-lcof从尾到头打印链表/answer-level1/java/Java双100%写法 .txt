双100%写法 先遍历链表长度 然后反着填充数组
先没理解头结点是否带值,就一直出问题..
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
    public int[] reversePrint(ListNode head) {
        ListNode l1 = head , l2 =head;
        int count = 0;
        while(l1 != null){
            l1 = l1.next;
            count++;
        }
        int[] res = new int[count];
    
        while( l2 != null ){
            
           res[--count] = l2.val; 
           l2 = l2.next; 
        }
        return res;
    }
}
```
