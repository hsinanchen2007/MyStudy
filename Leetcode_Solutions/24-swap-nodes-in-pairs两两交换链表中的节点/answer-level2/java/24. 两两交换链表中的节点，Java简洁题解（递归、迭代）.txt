# 审题
1. 不能交换值，要节点交换

# 思路
1. 迭代，最近重复问题abc简化
2. 递归

# 代码实现
1. 迭代，最近重复问题abc简化
2. 递归
3. 旧代码

## 1.迭代

```java
/**
    * 迭代
    * 0 ms	37.5 MB
    *
    * @param head
    * @return
    */
private ListNode traverseSolution(ListNode head) {
    ListNode pre = new ListNode(0);
    pre.next = head;
    ListNode ret = pre;
    while (head != null && head.next != null) {
        // abcd标记，简化
        ListNode first = pre;
        ListNode second = head;
        ListNode third = head.next;
        ListNode fourth = head.next.next;

        // 交换
        first.next = third;
        second.next = fourth;
        third.next = second;

        // 移动2位，注意节点交换了
        head = fourth;
        pre = second;
    }
    return ret.next;
}
```

## 2 递归

```java
/**
    * 递归
    * 0 ms	37.3 MB
    *
    * @param head
    * @return
    */
private ListNode recursiveSolution(ListNode head) {
    // 1 终结
    if (head == null || head.next == null) {
        return head;
    }
    // 2 当前,abc简化
    ListNode first = head;
    ListNode second = head.next;
    // 3 下探
    ListNode third = recursiveSolution(head.next.next);
    // 4 清理，反转
    second.next = first;
    first.next = third;
    return second;
}
```

## 3.旧代码

```java
public ListNode swapPairs201911011(ListNode head) {
    if (head == null || head.next == null) {
        return head;
    }
    ListNode end = head.next;

    ListNode pre = null;
    ListNode cur = head;
    ListNode curNext;
    while (cur != null && cur.next != null) {
        curNext = cur.next;
        ListNode tmp = curNext.next;
        curNext.next = cur;
        cur.next = tmp;
        if (pre != null) {
            pre.next = curNext;
        }

        pre = cur;
        cur = tmp;
    }

    return end;
}

public ListNode swapPairsRecursive(ListNode head) {
    if (head == null || head.next == null) {
        return head;
    }

    ListNode end = swapPairsRecursive(head.next.next);
    ListNode tmp = head.next;
    head.next = end;
    tmp.next = head;

    end = tmp;

    return end;
}
```