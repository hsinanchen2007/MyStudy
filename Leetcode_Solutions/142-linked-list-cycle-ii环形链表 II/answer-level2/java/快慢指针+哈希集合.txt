# 快慢指针

假设，非环长度：M，环长度：N，环内节点编号为0到N-1
**状态1: 慢指针入环时**
    慢指针经过M步，处于位置0。快指针经过2M步，位于M%N位置
**状态2: 快慢相遇**
    快指针每次逼近慢指针1步，共需要N-(M%N)步相遇
**状态3: 到环头**
    快慢指针与环头的距离为：N - [N - (M%N)] = M%N步
**如何判断到环头**
    非环长度为M，因此一个指针从头开始走M步，恰好与慢指针走M%N步在环头相遇 
```
public class Solution {
    public ListNode detectCycle(ListNode head) {
        if (head == null || head.next == null) return null;
        ListNode slow = head;
        ListNode fast = head;
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;
            if (slow == fast) break;
        }
        if (fast != slow) return null;
        ListNode travel = head;
        while (travel != fast) {
            travel = travel.next;
            fast = fast.next;
        }
        return fast;
    }
}
```


# 哈希集合
```
public class Solution {
    public ListNode detectCycle(ListNode head) {
        Set<ListNode> hashSet = new HashSet<>();
        ListNode travel = head;
        while (travel != null) {
            if (hashSet.contains(travel)) return travel;
            hashSet.add(travel);
            travel = travel.next;
        }
        return null;
    }
}
```
