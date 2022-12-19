### 解题思路
1.将不重复的数据放入哈希表
2.重复的数据进行判断，进行跳过
3.使用双指针，
4.有新元素加入，prev = current ，current后移
5.无新元素加入，pre.next = current.next current 后移

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
    public ListNode removeDuplicateNodes(ListNode head) {
        if(head == null || head.next == null ) return head;
        ListNode current = head;
        ListNode prev = new ListNode(0);
        prev.next = head;
        Set<Integer> s = new HashSet<Integer>();
        while(current!=null){
            if(!s.contains(current.val)){
                s.add(current.val);
                prev = current;
            }
            else{
                prev.next = current.next;
            }
            current=current.next;
        }
        return head;
    }
}
```