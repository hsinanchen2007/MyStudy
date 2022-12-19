### 解题思路
定义三个指针 s, e, p
![1.jpg](https://pic.leetcode-cn.com/a34cc6b8e1dd8a00ae8d7ceee13e77546dfc208569a13c861e08be9347d3f4f9-1.jpg)
![2.jpg](https://pic.leetcode-cn.com/26f1553d14a725ef76e898115b918d400162b23637467afc6aa8fd6389973436-2.jpg)

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
    public ListNode swapPairs(ListNode head) {
        ListNode ret = new ListNode(0);
        ret.next = head;
        if(head == null) return head;
        ListNode start = head, end = head, p = ret;
        while(start.next != null){
            start = start.next;
            p.next = start;
            end.next = start.next;
            start.next = end;
            p = end;
            if(end.next == null) break;
            start = p.next;
            end = start;

           
        }
        return ret.next;
    }
}
```