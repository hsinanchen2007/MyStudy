### 解题思路
此处撰写解题思路
利用非尾递归内层先执行的特征将与节点ptr相对称的节点temp带出进行比较。
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
    private ListNode temp;

    public boolean isPalindrome(ListNode head) {
        
        ListNode ptr = head;
        temp = head;

        return recursive(ptr);
    }

    private boolean recursive(ListNode ptr) {
        //边界
        if(ptr == null) {
            return true;
        }

        //主逻辑
        if(!recursive(ptr.next)) return false;
        if(ptr.val != temp.val) return false;
        temp = temp.next;

        return true;
    }

}
```