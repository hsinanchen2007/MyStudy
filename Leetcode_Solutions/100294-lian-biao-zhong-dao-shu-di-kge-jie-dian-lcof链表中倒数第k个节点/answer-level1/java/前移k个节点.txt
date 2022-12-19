### 解题思路
执行用时 : 0 ms , 在所有 Java 提交中击败了 100.00% 的用户 
内存消耗 : 38.2 MB , 在所有 Java 提交中击败了 100.00% 的用户

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
        if(head==null){
            return null;
        }

        ListNode temp = head;
        ListNode noKNode = null;;
        int currentIndex = 1;
        while(temp!=null){
            if(currentIndex<k){
                currentIndex++;
            }else if(currentIndex==k){
                noKNode = head;
                currentIndex++;
            }else{
                noKNode = noKNode.next;
            }
            temp = temp.next;
        }
        return noKNode;
    }
}
```