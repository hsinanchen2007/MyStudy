### 解题思路
分两步：先判断链表中是否有环，有环就逐个比较找出入环的第一个节点
![image.png](https://pic.leetcode-cn.com/eb37a6f3004eafe8621c2ac85ef44c83472ccf9621a103fe2778a52791b9f759-image.png)

### 代码

```java
public class Solution {
    public ListNode detectCycle(ListNode head) {
        if(head==null|| head.next==null)return null;
        ListNode p = head;
        ListNode q = head;
        boolean b = false;
        //先判断是否有环
        while(p.next!=null&&p.next.next!=null){
            p = p.next.next;
            q = q.next;
            if(q == p){
                b = true;
                break;
            }
        }
        //有环则逐个查找
        if(b){
            ListNode n = head;
            while(n!=q){
                n = n.next;
                q = q.next;
            }
            return n;
        }
        return null;
    }
}
```