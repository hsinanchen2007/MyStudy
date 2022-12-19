### 解题思路
如果是递归解法，可以这么理解removeDuplicateNodes(head)函数，如果head.val已经重复了那就去掉了head节点，处理head.next节点。
如果head没有重复，那就head.next = removeDuplicateNodes(head.next)。很好理解。非递归代码就是讲重复的值跳过去。

### 代码
递归解法

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
    private Set<Integer> set = new HashSet<>();

    public ListNode removeDuplicateNodes(ListNode head) {
        if(head == null )
            return head;
        if(set.contains(head.val)){
            return removeDuplicateNodes(head.next);
        }else{
            set.add(head.val);
            head.next = removeDuplicateNodes(head.next);
            return head;
        }
    }
}
```
非递归解法
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
        if(head == null || head.next == null)
            return head;
       Set<Integer> set = new HashSet<>();
       ListNode cur = head;
       set.add(cur.val);
       ListNode next = cur.next;
       while(next != null){
           while(set.contains(next.val) && next !=null){
                next = next.next;
                if(next == null){
                    cur.next = null;
                    return head;
                }     
           }
            set.add(next.val);
            cur.next = next;
            cur = cur.next;
            next = next.next;
       }
       return head;
    }
}
```
