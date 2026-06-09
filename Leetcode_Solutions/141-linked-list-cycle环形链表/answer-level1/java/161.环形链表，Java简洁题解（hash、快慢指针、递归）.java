# 审题
1. 只输出是否有环
2. 可以用 O(1)（即，常量）内存
3. 题目并没有说是否有重复元素

# 思路
1. hash表，重复则有环
2. 双指针：快慢指针

# 反馈
1. 会有重复数据
2. 不能用值判重，但可以用节点判重
3. 异常方式
4. 递归，可以不管原对象

# 代码实现
1. hash表
2. 快慢指针
3. 快慢指针异常版
4. 递归：破坏链表结构
5. 递归：标记法

## 1.hash表

```java
private boolean hashSolution(ListNode head) {
    Set<ListNode> set = new LinkedHashSet<>();
    while (head != null) {
        if (set.contains(head)) {
            return true;
        }
        set.add(head);
        head = head.next;
    }
    return false;
}
```

## 2.双指针：快慢指针

```java
private boolean slowAndFastSolution(ListNode head) {
    if (head == null) {
        return false;
    }
    ListNode slow = head;
    ListNode fast = head.next;
    while (fast != null && fast.next != null) {
        if (slow.equals(fast)) {
            return true;
        }
        slow = slow.next;
        fast = fast.next.next;
    }

    return false;
}
```

## 3.快慢指针异常版

```java
private boolean slowAndFastExceptionSolution(ListNode head) {
    try {
        ListNode slow = head;
        ListNode fast = head.next;
        while (!slow.equals(fast)) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return true;
    } catch (Exception e) {
        return false;
    }
}
```

## 4.递归：破坏链表结构

```java
private boolean traverseBreakSolution(ListNode head) {
    if (head == null || head.next == null) {
        return false;
    }
    // 判断是否是自环状态
    if (head == head.next) {
        return true;
    }
    // 让遍历过的节点自环
    ListNode breaker = head.next;
    head.next = head;
    return traverseBreakSolution(breaker);
}
```

## 5.递归：标记法

```java
private boolean traverseMarkSolution(ListNode head) {
    if (head == null) {
        return false;
    }
    if (head.val == 0xcafebabe) {
        return true;
    }
    head.val = 0xcafebabe;
    return traverseMarkSolution(head.next);
}
```

## 6.旧代码

```java
public boolean hasCycle20191102(ListNode head) {
    Set<ListNode> visited = new HashSet<>();
    boolean contains = false;
    while (head != null && !contains) {
        contains = visited.contains(head);
        visited.add(head);
        head = head.next;
    }

    return contains;
}

public boolean hasCycleFastAntSlow(ListNode head) {
    ListNode fast = head;
    ListNode slow = head;
    while (fast != null && fast.next != null && slow != null) {
        fast = fast.next.next;
        slow = slow.next;
        if (fast == slow) {
            return true;
        }
    }

    return false;
}
```