**我的公众号里有一篇文章详细总结了链表快慢指针的各种情况！点击这里查看：[双指针×链表问题：快慢指针](https://mp.weixin.qq.com/s?__biz=MzA5ODk3ODA4OQ==&mid=2648167055&idx=1&sn=0eae5debd1c012c16d939982e7dc48aa&chksm=88aa22c9bfddabdf4fb584057b563f4c26c62d177701c0255816b657f9adfa5ea8bf1c726be8&token=1387195628&lang=zh_CN#rd)。**

这道题是一个典型的**快慢指针**的例题。快慢指针是双指针的一个分支，在链表问题中是很重要的一个技巧。我们可以从这道题中学习双指针技巧的使用。

## 题目解法

### 常规做法

寻找链表中点的常规做法是两步走：

+ 先遍历一遍链表，计算链表的长度 $n$；
+ 再遍历一遍链表，找到第 $n/2$ 个元素。

这种方法需要遍历链表两遍。有没有可能用一次遍历就找到中点呢？答案是用**快慢指针**。

### 快慢指针做法

使用慢指针 `slow` 和快指针`fast` 两个指针同时遍历链表。快指针一次前进两个结点，速度是慢指针的两倍，如下图所示：

![快慢指针不同速度前进（动图）](https://pic.leetcode-cn.com/404d110d9578be8c86697c991fa35a86412224911eb5d49a0ad001af59d5339e.gif)

这样，当快指针到达链表尾部时，慢指针正好到达链表的中部。

不过，这个方法并没有减少时间复杂度的量级 —— 时间复杂度仍然是 $O(n)$。不过能减少一次遍历，也是节省了算法时间。链表类题目就是需要这样减少一次遍历的技巧。

两个注意点：

1. 循环的条件是 `fast != null && fast.next != null`，防止出现空指针异常。
2. 注意链表结点为奇数个和偶数个的时候，链表中点的含义不一样。不过这种写法正好能满足题意，小伙伴们可以自己在纸上画一画最后 `slow` 指针落在什么位置。

```Java []
public ListNode middleNode(ListNode head) {
    ListNode fast = head;
    ListNode slow = head;
    while (fast != null && fast.next != null) {
        // fast 一次前进两个元素，slow 一次前进一个元素
        fast = fast.next.next;
        slow = slow.next;
    }
    // 链表元素为奇数个时，slow 指向链表的中点
    // 链表元素为偶数个时，slow 指向链表两个中点的右边一个
    return slow;
}
```

## 更多快慢指针题目

链表数据类型的特点决定了它只能单向顺序访问，而不能逆向遍历或随机访问（按下标访问）。很多时候，我们需要使用快慢指针的技巧来实现一定程序的逆向遍历，或者减少遍历的次数。

链表中的快慢指针还有几道经典的题目：

+ [19. 删除链表的倒数第N个节点](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list) 这道题的快慢指针比较特殊，两个指针速度一样，只是让一个先出发
+ [141. 环形链表](https://leetcode-cn.com/problems/linked-list-cycle/) / [142. 环形链表 II](https://leetcode-cn.com/problems/linked-list-cycle-ii/) 通过快慢指针套圈的方法来判断链表中是否有环

这些题目的解法都在我的公众号文章中有总结，文章链接在此：[LeetCode 例题精讲 | 05 双指针×链表问题：快慢指针](https://mp.weixin.qq.com/s?__biz=MzA5ODk3ODA4OQ==&mid=2648167055&idx=1&sn=0eae5debd1c012c16d939982e7dc48aa&chksm=88aa22c9bfddabdf4fb584057b563f4c26c62d177701c0255816b657f9adfa5ea8bf1c726be8&token=1387195628&lang=zh_CN#rd)。喜欢的话欢迎关注、在看哦！这是我正在写作的系列文章《LeetCode 例题精讲》中的一篇，目前正在公众号上连载。

扫码关注我的公众号 ⇩⇩⇩：

![wechat](https://pic.leetcode-cn.com/b28ff0d73677b63a4793b185a7844ab37bd357592f0de41aba854ab3e74ab6ee.jpg)

  