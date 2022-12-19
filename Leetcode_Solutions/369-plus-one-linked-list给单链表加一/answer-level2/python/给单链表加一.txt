#### 方法一：哨兵头节点

**加法运算**

找出最靠右的不是 9 的数字，将该数字加 1。然后将该数字之后所有的 9 改成 0。

下面是一个简单的例子，根据上述描述的方法可以得到正确答案。

![simple](https://pic.leetcode-cn.com/Figures/369/simple.png)

下面是一个相对复杂一点的例子，根据上述描述的方法也可以得到正确答案。

![diff](https://pic.leetcode-cn.com/Figures/369/diff.png)

但下面这个例子就有点问题了。

![diff](https://pic.leetcode-cn.com/Figures/369/handle.png)

**哨兵头结点**

针对最后一个案列，需要用到 [哨兵节点](https://en.wikipedia.org/wiki/Sentinel_node)。树和链表问题中经常会用到哨兵节点，它们的主要目的是将边缘数据的处理常规化。
 
对于下面这个例子，在最左边增加一个数值为 0 的哨兵节点，这样就能保证一定有数值不为 9 的节点存在。

![diff](https://pic.leetcode-cn.com/Figures/369/sentinel.png)

**算法**

- 初始化哨兵节点 `ListNode(0)`，同时将它设为新的头节点：`sentinel.next = head`。

- 找到最靠右的数值不为 9 的节点。

- 将该节点的数值加 1。

- 将该节点之后所有节点数值改为 0。

- 如果哨兵节点的数值为 1，直接返回哨兵节点，否则返回原始头节点 `sentinel.next`。

**实现**

```python [solution1-Python]
class Solution:
    def plusOne(self, head: ListNode) -> ListNode:
        # sentinel head
        sentinel = ListNode(0)
        sentinel.next = head
        not_nine = sentinel
        
        # find the rightmost not-nine digit
        while head:
            if head.val != 9:
                not_nine = head
            head = head.next 
        
        # increase this rightmost not-nine digit by 1
        not_nine.val += 1
        not_nine = not_nine.next 
        
        # set all the following nines to zeros
        while not_nine:
            not_nine.val = 0
            not_nine = not_nine.next
        
        return sentinel if sentinel.val else sentinel.next
```

```java [solution1-Java]
class Solution {
  public ListNode plusOne(ListNode head) {
    // sentinel head
    ListNode sentinel = new ListNode(0);
    sentinel.next = head;
    ListNode notNine = sentinel;

    // find the rightmost not-nine digit
    while (head != null) {
      if (head.val != 9) notNine = head;
      head = head.next;
    }
    
    // increase this rightmost not-nine digit by 1
    notNine.val++;
    notNine = notNine.next;
    
    // set all the following nines to zeros
    while (notNine != null) {
      notNine.val = 0;
      notNine = notNine.next;
    }
    
    return sentinel.val != 0 ? sentinel : sentinel.next;
  }
}
```

**复杂度分析**

* 时间复杂度：$O(N)$，最多只需遍历两遍链表。
 
* 空间复杂度：$O(1)$。