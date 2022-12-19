### 解题思路
经典解法，一个指针先跑K步，然后头指针和这个指针一起跑，等到这个指针跑到尾巴的时候，头指针所在的位置正好就是倒数第K个位置。
如果你还不理解，说明刷的题目比较少，无他 唯手熟尔

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
    List<Integer> list = new ArrayList<>();

    public int kthToLast(ListNode head, int k) {
        ListNode kNode = head;
        while (k > 0) {
            k--;
            kNode = kNode.next;
        }

        while (head != null && kNode != null) {
            kNode = kNode.next;
            head = head.next;
        }
        return head.val;
    }
}
```