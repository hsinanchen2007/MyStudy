直接上代码吧
```
public class Solution {
    public boolean hasCycle(ListNode head) {
        if (head == null || head.next == null || head.next.next == null) {
            return false;
        }

        // 一个一步，一个两步，若有环，迟早会相遇
        ListNode stepOne = head.next;
        // 不能直接head.next.next，防止head.next为空
        ListNode stepTwo = head.next;
        while (stepOne != null && stepTwo != null) {
            stepTwo = stepTwo.next;
            if (stepTwo == null) {
                return false;
            }
            if (stepOne == stepTwo) {
                return true;
            }
            stepOne = stepOne.next;
            stepTwo = stepTwo.next;
        }
        return false;
    }
}
```
