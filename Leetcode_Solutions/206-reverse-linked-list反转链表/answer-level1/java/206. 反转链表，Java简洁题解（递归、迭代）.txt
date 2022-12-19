# 审题
1. 单链表反转
2. 递归、迭代

# 思路
1. 递归
2. 迭代

# 代码实现
1. 递归
2. 迭代
3. 旧代码

## 1.递归

```java
/**
    * 递归
    * 0 ms	38.5 MB
    * 找到结束、起始的边界来推算
    *
    * @param head
    * @return
    */
private ListNode recursiveSolution(ListNode head) {
    // 1 终结条件
    if (head == null || head.next == null) {
        return head;
    }
    // 2 当前层
    // 3 下层
    ListNode tail = recursiveSolution(head.next);
    // 4 清理 反转
    head.next.next = head;
    head.next = null;
    return tail;
}
```

## 2.迭代

```java
/**
    * 迭代
    * 找到最近重复问题 a(pre) b(head) c(head.next)
    * 0 ms	38 MB
    *
    * @return
    * @param head
    */
private ListNode traverseSolution(ListNode head) {
    ListNode pre = null;
    while (head != null) {
        // 简化标记abc
        ListNode first = pre;
        ListNode second = head;
        ListNode third = head.next;

        // 反转
        second.next = first;

        // 移动到下一阶段
        pre = second;
        head = third;
    }
    return pre;
}
```

## 3.旧代码

```java

public ListNode reverseList20191031(ListNode head) {
    if (head == null || head.next == null) {
        return head;
    }
    ListNode[] list = new ListNode[4086];
    int index = -1;
    while (head != null) {
        index++;
        list[index] = head;
        head = head.next;
    }

    head = list[index];

    ListNode tmp = head;
    for (int i = index - 1; i >= 0; i--) {
        tmp.next = list[i];
        tmp = tmp.next;
    }
    tmp.next = null;
    return head;
}

/**
    * 初始状态 3 <-next *2* pre-> 1 或者 2 <-next *1* <-x- NULL
    * 1 创造一个虚拟的前驱指针 3 <-next *2* pre-> 1
    * 1.1 如果是第一次，前驱指针指向NULL 2 <-next *1* pre-> NULL
    * 2 打断后级指针，把后级指向前驱节点 3 <-x- *2* -> 1 => 3 <-x- *2* pre-> next-> 1
    * 3 前驱指针指向当前节点（当前指针前移后，就变为指向前驱节点的）3 pre-> *2* next-> 1
    * 4 当前指针前移到之前后级指针断掉的节点 4 <-next *3* pre-> 2 next-> 1
    * 5 重复以上过程 4 <-next *3* pre-> 2
    *
    * @param head
    * @return
    */
public ListNode reverseListSimple(ListNode head) {
    ListNode pre = null;
    ListNode cur = head;
    ListNode temp;

    while (cur != null) {
        temp = cur.next;

        cur.next = pre;
        pre = cur;
        cur = temp;
    }

    return pre;
}

public ListNode reverseListRecursive(ListNode head) {
    if (head == null || head.next == null) {
        return head;
    }

    ListNode pre = reverseListRecursive(head.next);
    head.next.next = head;
    head.next = null;
    return pre;
}
```