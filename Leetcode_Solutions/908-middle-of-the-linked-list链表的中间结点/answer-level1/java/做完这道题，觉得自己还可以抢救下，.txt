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

        List<Integer> result = new ArrayList<>();
        ListNode tmp = head;
        while (tmp != null){

            result.add(tmp.val);
            tmp = tmp.next;
        }
        int value = result.size()/2;
        if (value == 0){
            int i = 0;
            while (i <value-1){
                head = head.next;
                i++;
            }
            return head;
        }else {
            int i = 0;
            while (i < value){
                head = head.next;
                i++;
            }
            return head;
        }
    }
}
```