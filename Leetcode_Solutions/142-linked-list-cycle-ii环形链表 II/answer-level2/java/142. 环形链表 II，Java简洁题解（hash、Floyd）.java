# 审题
1. 不能修改链表
2. 不用额外空间也可以解决
3. 返回环位置节点

# 思路
1. hash
2. 双指针：快慢指针

# 反馈
1. 快慢指针使用Floyd算法

# 代码实现
1. hash
2. floyd

## 1.hash

```java
private ListNode hashSolution(ListNode head) {
    Set<ListNode> set = new HashSet<>();
    while (head != null && head.next != null) {
        if (set.contains(head)) {
            return head;
        }
        set.add(head);
        head = head.next;
    }
    return null;
}
```

## 2.floyd

```java

private ListNode floydSolution(ListNode head) {
    ListNode tail = getFloydIntersection(head);
    if (tail == null) {
        return null;
    }

    while (head != tail) {
        head = head.next;
        tail = tail.next;
    }
    return head;
}

private ListNode getFloydIntersection(ListNode head) {
    if (head == null || head.next == null) {
        return null;
    }
    // floyd交点需要同时出发
    ListNode fast = head;
    ListNode slow = head;
    while (fast != null && fast.next != null) {
        slow = slow.next;
        fast = fast.next.next;
        if (slow.equals(fast)) {
            return slow;
        }
    }
    return null;
}
```