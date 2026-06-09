### 解题思路
使用ArrayList的自带特性，从头到尾遍历链表的过程中，每次都将读取到的值加到List的最开头。这样生成的List就是反过来的所有数值。再将对象数值转成基本类型即可。
内存击败100%用户。

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
        if (null == head) {
            return new int[0];
        }
        List<Integer> list = new ArrayList<>();
        list.add(head.val);
        while (head.next != null) {
            list.add(0, head.next.val);
            head = head.next;
        }
        int[] result = new int[list.size()];
        int index = 0;
        for (Integer ele : list) {
            result[index++] = ele;
        }
        return result;
    }
}
```