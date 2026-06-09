***我的[leetcode解题集](https://github.com/JuiceZhou/Leetcode)，持续更新。***

使用三根指针，slow/fast表示重复元素的起始位置，pre表示slow的前置节点。

```
public ListNode deleteDuplicates(ListNode head) {
    ListNode fakeHead = new ListNode(0), pre = fakeHead, slow = head, fast = head;
    fakeHead.next = head;

    while (fast != null && fast.next != null) {
        //如果当前元素不是重复元素
        while (fast.next != null && slow.val != fast.next.val) {
            pre = slow;
            slow = slow.next;
            fast = slow;
        }
        //如果是重复元素，则获取重复元素的起点和终点
        while (fast.next != null && slow.val == fast.next.val) {
            fast = fast.next;
        }
        //删除重复元素
        if (slow != fast) {
            pre.next = fast.next;
            slow = pre.next;
            fast = slow;
        }
    }
    return fakeHead.next;
}
```
