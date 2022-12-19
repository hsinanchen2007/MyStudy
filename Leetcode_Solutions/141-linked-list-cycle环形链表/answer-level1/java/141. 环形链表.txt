### 解题思路
循环链表，快慢指针，如果指向同一个指针，则存在环形。
![image.png](https://pic.leetcode-cn.com/c3de7b17ea8d6ed2938b38bb40fa6135a271f4f4d11f46bbb86aadde4423c8c2-image.png)

### 代码

```java

public class Solution {
    public boolean hasCycle(ListNode head) {
        if(head == null || head.next == null)return false;
        ListNode q = head;
        ListNode p = head;
        while(q.next!=null&&q.next.next!=null){
            q = q.next.next;
            p = p.next;
            if(q == p)return true;
        }
        return false;
    }
}
```