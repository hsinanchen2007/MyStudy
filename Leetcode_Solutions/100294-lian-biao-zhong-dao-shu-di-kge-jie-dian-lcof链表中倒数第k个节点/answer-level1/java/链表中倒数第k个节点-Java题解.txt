### 解题思路
双指针法
针对链表，双指针法是很常见的。
此题目需要考虑k为0和大于链表长度的特殊情况。
设立双指针皆指向head节点，其中右指针j向右移动k个节点，与i形成k个节点的距离。此后i、j同时向右移动（保持k个节点的距离）直至j为空（即遍历完毕）。

### 步骤：
1. 创建双指针均指向head
2. 对k进行判断的同时令右指针j与左指针i保持k个距离。若k大于链表长度，那么j移动了k个单位后自然指向null，返回null；若k为0，则i与j都同时向右移动直至他们遍历完毕指向null，返回null
3. 若k理想，那么右指针j向右移动k个节点后于i保持k个节点的距离，再同时向右移动，当j指向空，那么i则指向倒数第k个节点
4. 返回此时的i

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
        ListNode i = head;
        ListNode j = head;
        for(int a = 0;a < k;a++){
            if(j == null) return null;
            j = j.next;  
        }

        while(j != null){
            i = i.next;
            j = j.next;
        }
        return i;
    }
}
```