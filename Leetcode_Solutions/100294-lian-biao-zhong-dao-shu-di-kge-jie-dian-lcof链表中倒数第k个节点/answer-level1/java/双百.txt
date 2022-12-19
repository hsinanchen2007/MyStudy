### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/ae516ad937a4fa33f3b0d7103a7b24e7132f05cb0e3b2344b6f56fe8b69b64cf-image.png)
定义两个指针，first和last，让first先走k步，然后first和last一起走，如果first为空，那么此时last所在的位置即为倒数第k个节点。
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
         ListNode first = head;
        ListNode last = head;
        for (int i = 0; i < k; i++) {
            first = first.next;
        }
        while(first!=null){
            first = first.next;
            last = last.next;
        }
        return last;
    }
}
```