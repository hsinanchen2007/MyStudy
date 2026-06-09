### 解题思路
此处撰写解题思路
还可以反转链表，但感觉没必要，都是遍历两次
执行用时 :
2 ms
, 在所有 Java 提交中击败了
60.00%
的用户
内存消耗 :
40.1 MB
, 在所有 Java 提交中击败了
100.00%
的用户
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
        List<Integer> tmp = new ArrayList<>();
        int tot = 0, cnt = 0;
        while (head != null){
            tot++;
            tmp.add(head.val);
            head = head.next;
        }
        cnt = tot;
        int[] res = new int[cnt];
        int i = 0;
        while (cnt != 0){
            res[i] = tmp.get(cnt-1);
            tmp.remove(cnt-1);
            cnt--;
            i++;
        }
        return res;
    }
}
```