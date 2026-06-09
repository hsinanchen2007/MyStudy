### 解题思路
先遍历链表里的数据到List中, 然后将List中的数据倒序输出到数组并返回即可

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
        List<Integer> list = new ArrayList<>();
        ListNode p = head;
        while(p != null) {
            list.add(p.val);
            p = p.next;
        }
        //倒序输出到数组中
        int len = list.size();
        int[] result = new int[len];
        for(int i = 0; i < len; i++) {
            result[i] = list.get(len-i-1);
        }
        return result;
    }
}
```