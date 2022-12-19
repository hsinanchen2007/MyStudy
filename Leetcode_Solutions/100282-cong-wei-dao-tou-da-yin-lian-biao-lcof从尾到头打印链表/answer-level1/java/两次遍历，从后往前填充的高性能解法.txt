### 复杂度分析
时间复杂度：O(2n)
空间复杂度：O(n)
其中 n 为链表长度

### 解题思路
遍历链表获取链表长度，开辟回传数组
再次遍历链表，从最后一个元素开始往前填充链表

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
        ListNode node = head;
        int count = 0;

        // 获取链表长度
        while (node != null) {
            count++;
            node = node.next;
        }

        int[] ans = new int[count];
        node = head;

        // 从后往前填充数组
        for (int i = count - 1; i >= 0; i--) {
            ans[i] = node.val;
            node = node.next;
        }
        
        return ans;
    }
}
```