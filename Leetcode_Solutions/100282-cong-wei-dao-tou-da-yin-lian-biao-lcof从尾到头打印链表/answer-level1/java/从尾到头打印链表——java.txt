### 解题思路
**核心思想：栈， 栈特点：先进后出；**
1、我们先把全部的元素，从头到尾添加到Stack中去。
2、通过stack即可获取到元素个数，从而初始化数组大小。
3、直接遍历，挨个挨个从stack取出，因为栈是先进后出，所以就是倒序添加到数组当中。

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
        ListNode item = head;
        Stack<Integer> stack = new Stack<>();
        while (item != null) {
            stack.push(item.val);
            item = item.next;
        }

        int index = stack.size();
        int[] result = new int[index];
        for (int i = 0; i < index; i++) {
            result[i] = stack.pop();
        }

        return result;
    }
}
```