# 快慢指针
快指针一次走两步，慢指针一次走一步，若有环必将相遇
证明方式1：进入环之后，无论快指针、慢指针在什么位置，每走一次快指针将会逼近慢指针一个位置，最终必将相遇
证明方式2:假设快指针与慢指针不会相遇，即某一次快指针正好跳过了慢指针跑到慢指针的前一个位置，那么在此前一个位置必将相遇
```
public class Solution {
    public boolean hasCycle(ListNode head) {
        if (head == null) return false;
        if (head == head.next) return true;
        ListNode fast = head;
        ListNode slow = head; 
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;
            if (fast == slow) return true;
        }
        return false;
    }
}
```
时间复杂度: O(n), 空间复杂度O(1).
# 哈希集合
遍历链表，若重复必有环
```
public class Solution {
    public boolean hasCycle(ListNode head) {
        Set<ListNode> hashSet = new HashSet<>();
        ListNode travel = head;
        while (travel != null) {
            if(hashSet.contains(travel)) return true;
            hashSet.add(travel);
            travel = travel.next;
        }
        return false;
    }
}
```
时间复杂度: O(n), 空间复杂度O(n).
