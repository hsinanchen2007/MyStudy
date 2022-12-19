![image.png](https://pic.leetcode-cn.com/c63cb2b21694a65c0f781c3cd0adac0ae299eb7258b360c11d76ca7ed2f4cd38-image.png)

## 解题分析
首先我们要明确这道题的难点在哪？这道题的难点就在于我们最开始只有一个头节点，至于这个头节点后面有没有子节点，子节点有没有它的子节点，这个，我们是不知道的，也就是说，我们并不知道，到底这个链表的长度是多少，要知道，链表可不像数组，我们找一个元素是要从头开始遍历的。

有的同学可能要说了，这个简单，我们遍历一次，就知道这个链表有多长了，这样我们就能算出倒数第n个是正数第几个了，再遍历到这个元素，就知道结果了。

但是一般面试到这道题就是最多只允许遍历一遍链表。

我们假设一下，有一个直线跑道是500米，如果我们一直以前面那个人后面200米的距离在跟跑，那么当前面那个人到终点之后我们离终点有多少米，不用说，肯定是200米啊。

所以我们需要一个跑的快的先去链表上跑，至于有多快呢，拉跑的慢的n-1个节点（因为第三名比第一名慢的是两步不是三步）。这样等跑的快的到达链表末尾（就是下一个节点为空），那么慢的所在的位置就是倒数第n个节点。

这就是著名的双指针算法，一快一慢。

这道题除了考察我们双指针之外，最主要的还要考察我们代码的健壮性，比如倒数第5个，链表一共就3个节点，你会不会空指针，比如头节点就是空，你会不会又空指针呢?

## 代码（JAVA实现）
ps：这里笔者使用的jdk为1.8版本

```java
public class FindKthToTail {

    public static void main(String[] args) {

        ListNode kthToTail = findKthToTail(LinkedListUtil.getLinkedList(new int[]{1, 2, 3}), 3);
        System.out.println(kthToTail.val);
    }

    public static ListNode findKthToTail(ListNode head, int k) {

        ListNode pre = head;
        ListNode aft = head;

        for (int i = 0; i < k - 1; i++) {
            if (Objects.isNull(pre) || Objects.isNull(pre.next)) {
                return null;
            }
            pre = pre.next;
        }

        while (Objects.nonNull(pre.next)) {
            pre = pre.next;
            aft = aft.next;
        }

        return aft;
    }
}
```
LinkedListUtil为笔者自己定义方便做链表题目的工具类，代码如下：

```java

public class LinkedListUtil {

    /**
     * 获取一个链表
     */
    public static ListNode getLinkedList(int[] numbers) {

        if (numbers == null || numbers.length == 0) {
            return null;
        }

        ListNode first = new ListNode(numbers[0]);
        ListNode intermediateVariables = first;

        for (int i = 1; i < numbers.length; i++) {
            ListNode temp = new ListNode(numbers[i]);
            intermediateVariables.next = temp;
            intermediateVariables = intermediateVariables.next;
        }

        return first;
    }

    /**
     * 打印一个链表
     */
    public static void printLinkedList(ListNode first) {
        ListNode intermediateVariables = first;

        while (!Objects.isNull(intermediateVariables)) {

            System.out.printf("%s-> ", intermediateVariables.val);
            intermediateVariables = intermediateVariables.next;
        }
        System.out.println();

    }

    // 测试工具类
    public static void main(String[] args) {
        printLinkedList(getLinkedList(new int[]{1, 2, 3, 4, 5, 6, 7}));
    }
}
```
