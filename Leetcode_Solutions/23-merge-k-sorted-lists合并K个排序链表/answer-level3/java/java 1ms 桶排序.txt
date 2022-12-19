如果已知取值范围，可以使用桶排序，会有一个接近 O(n) 的复杂度。

示例代码如下：

```
private static int[] array = new int[1_0000];

public ListNode mergeKLists(ListNode[] lists) {
    if (lists == null || lists.length == 0) {
        return null;
    }
    if (lists.length == 1) {
        return lists[0];
    }
    int max = Integer.MIN_VALUE;
    int min = Integer.MAX_VALUE;
    for (ListNode list : lists) {
        while (list != null) {
            int val = list.val + 5000;
            array[val]++;
            list = list.next;
            if (val > max) {
                max = val;
            }
            if (val < min) {
                min = val;
            }
        }
    }
    ListNode head = new ListNode(0);
    ListNode point = head;
    for (int i = min; i <= max; i++) {
        int num = array[i];
        while (num-- > 0) {
            ListNode node = new ListNode(i - 5000);
            point.next = node;
            point = node;
        }
        array[i] = 0;
    }
    return head.next;
}
```

