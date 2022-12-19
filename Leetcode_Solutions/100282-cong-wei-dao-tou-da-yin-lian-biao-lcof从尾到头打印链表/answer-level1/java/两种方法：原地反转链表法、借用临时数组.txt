```
/**
 * 反转链表法.
 * 时间复杂度：O(n)，空间复杂度：O(n)
 */
public int[] reversePrintV2(ListNode head) {
    if (head == null) {
        return new int[0];
    }

    // 1.反转链表. 【关键】：创建新链表，利用哑节点
    ListNode dummy = new ListNode(-1);
    // 链表元素个数
    int count = 0;
    while (head != null) {
        // 暂存下一个节点
        ListNode tmp = head.next;

        // 主逻辑
        head.next = dummy.next;
        dummy.next = head;
        
        // 更新为下一个节点
        head = tmp;
        count++;
    }

    // 2.遍历新链表，将元素逐个放到新数组
    int[] nums = new int[count];
    int i = 0;
    ListNode p = dummy.next;
    while (p != null) {
        nums[i++] = p.val;
        p = p.next;
    }

    return nums;
}

/**
 * 借用ArrayList，也可创建一个数组来存储.
 * 时间复杂度：O(n)，空间复杂度：O(n)
 */
public int[] reversePrint(ListNode head) {
    if (head == null) {
        return new int[0];
    }

    // 1.将链表的所有元素放到List中
    List<Integer> list = new ArrayList<>();
    while (head != null) {
        list.add(head.val);
        head = head.next;
    }

    // 2.再将List中的数据倒序存到新数组中
    int[] resultArray = new int[list.size()];
    int count = 0;
    for (int i = list.size() - 1; i >= 0; i--) {
        resultArray[count++] = list.get(i);
    }

    return resultArray;
}
```
