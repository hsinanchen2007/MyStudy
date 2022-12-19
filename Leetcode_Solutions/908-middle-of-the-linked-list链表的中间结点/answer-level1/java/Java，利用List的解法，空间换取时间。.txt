
![批注 2020-03-23 142216.png](https://pic.leetcode-cn.com/777d1c26a063dc95093e397101c7da54ffd27839fb334391725a718c45cafbda-%E6%89%B9%E6%B3%A8%202020-03-23%20142216.png)

list存储所有的链表的结点,再得到中间位置的数即可。

```
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

        List<ListNode> list = new ArrayList<>();
        list.add(head);

        while(head.next!=null){
            head = head.next;
            list.add(head);
        }

        return list.get(list.size()/2);
    }
}
```

