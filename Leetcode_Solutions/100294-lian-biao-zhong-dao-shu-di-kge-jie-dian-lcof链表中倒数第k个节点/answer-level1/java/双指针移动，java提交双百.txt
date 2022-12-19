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
    public ListNode getKthFromEnd(ListNode head, int k) {
        //特殊情况
        if(head ==null || k <= 0){
            return null;
        }
        ListNode firstNode = head;
        ListNode secondNode;
        for(int i = 0; i < k-1; i++){
            // 加多一个判断，防止k过大，导致出错
            if(firstNode.next != null){
            firstNode = firstNode.next;
            }else{
                return null;
            }
            
        }
        secondNode = head;
        // 这里注意用对条件语句
        while(firstNode.next != null){
            firstNode = firstNode.next;
            secondNode = secondNode.next;
        }
        return secondNode;

    }
}
```