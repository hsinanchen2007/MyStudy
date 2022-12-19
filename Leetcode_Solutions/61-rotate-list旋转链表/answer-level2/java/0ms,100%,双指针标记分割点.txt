### 解题思路
![屏幕快照 2020-03-04 18.15.17.png](https://pic.leetcode-cn.com/f524dd71c311e1c128d9727f8aa0f4d57362b7f0acfa012cf78d12545a27587e-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-03-04%2018.15.17.png)


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
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null) {
            return head;
        }
        int val = k;
        ListNode dynamic = head;
        ListNode last = head;
        // 标记分割点
        while (k != 0) {
            if (last.next == null) {
                // 知道链表真实长度后，直接取余，走剩下的步骤
                k = val % (val - k + 1) + 1;
                last = head;
            } else {
                last = last.next;
            }
            k--;
        }
        // 如果last指到了头节点直接返回头节点就可以
        if (last == head) {
            return head;
        }
        // 进行分割
        while (last.next != null) {
            last = last.next;
            dynamic = dynamic.next;
        }
        // 进行拼接
        ListNode res = dynamic.next;
        dynamic.next = null;
        last.next = head;
        return res;
    }
}
```