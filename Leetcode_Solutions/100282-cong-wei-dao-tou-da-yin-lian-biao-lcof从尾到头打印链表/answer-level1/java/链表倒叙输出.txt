### 解题思路
正序遍历，并且存储到列表中。然后初始化数组，存储到数组中。

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
    public int[] reversePrint(ListNode head) {
        int[] res;
        if(head == null){
            return new int[0];
        }
        
        List<Integer> list = new ArrayList<>();
        ListNode tail = head;

        while(tail != null){
            list.add(tail.val);
            tail = tail.next;
        }

        res = new int[list.size()];

        for(int i = 0; i < list.size(); i++){
            res[i] = list.get(list.size()-1-i);
        }
        
        return res;
    }
}
```