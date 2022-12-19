## 数组逆序转换的方法

要想实现数组的逆序，方法有许多，如果只是打印那就跟简单了，可以类似遍历二叉树后序遍历那样递归，先去下个节点然后输出。当然今天我们并不是要输出，而是要真正的的改变链表的节点顺序。

我暂时先写了两个方法，当然这个题也可用栈(stack)来写，也是非常简单，相信你搞会了递归和双指针的话，栈也是手到擒来之。

### 一、递归

**注意事项**：

1. 我们只需要改变节点中的next的指向即可，无需做其他操作
2. 要花尽可能少的时间，也就是在遍历链表的时候一次性也修改指针的指向
3. 记得修改原来的头结点的指向，要指向null，要么就会出现遍历输出时的最后两个节点的死循环，而导致超时问题

**思路**

1. 创建一个全局变量(newFirst)来储存新链表的头结点
2. 进程序前，先判定空链表和一个节点的链表
3. 找到最后的节点是返回当前节点，更新新的头结点
4. 递归每次返回的都是下一层新链表的最后一个节点，然后只需在当前层插入新的尾节点然后返回

**图解**

![递归图示.png](https://pic.leetcode-cn.com/84363b7f834898b1e834a42e7cd4dea980982b6ab4608d96b3682ca8a337a639-%E9%80%92%E5%BD%92%E5%9B%BE%E7%A4%BA.png)

### 代码

```java
class Solution {
    //新的头结点
    ListNode newFirst;
    public ListNode reverseList(ListNode head) {
        //先判定空链表和一个节点的链表
        if (head == null || head.next == null) return head;
        //进入递归
        reverse(head);
        //更新新链表尾节点(以前链表的头结点)的指向
        head.next = null;
        return newFirst;
    }
    public ListNode reverse(ListNode head) {
        //递归终止：找到新链表头结点
       if (head.next == null) {
            newFirst = head;
            return head;
        }
        //在 返回的 下一层 新链表的最后一个节点 之后插入 当前层的尾节点
        reverse(head.next).next = head;
        //返回当前层的尾节点
        return head;
    }
}
```
![递归.png](https://pic.leetcode-cn.com/392e21d8d38a6cec658489abb4e0e891e6f0e66d7ec780726a58d5f24ab8a029-%E9%80%92%E5%BD%92.png)


### 二、双指针

**注意事项**：

1. 我们只需要改变节点中的next的指向即可，无需做其他操作
2. 要花尽可能少的时间，也就是在遍历链表的时候一次性也修改指针的指向
3. 记得修改原来的头结点的指向，要指向null，要么就会出现遍历输出时的最后两个节点的死循环，而导致超时问题
4. 使用双指针来遍历链表，简化单指针的难度
5. 在修改节点指向时，不要想反了，要不会出现意想不到的错误

**思路**

1. 使用两个指针来控制链表，便于重接链表
2. 进入循环，依次改变节点之间的指向
3. 最后判定条件，跳出循环

**图解**

![双指针图示.png](https://pic.leetcode-cn.com/b4f6ae2fe0e66d077dc1a9e1db004e7630eae7e55a5e64c53cb713de27f0c054-%E5%8F%8C%E6%8C%87%E9%92%88%E5%9B%BE%E7%A4%BA.png)

### 代码

```java
class Solution {
    public ListNode reverseList(ListNode head) {
        //先判定空链表和一个节点的链表
        if (head == null || head.next == null) return head;
        ListNode pre = null, now = head ,tem;
        while (now != null) {
            //更改指针
            tem = now.next;
            now.next = pre;
            pre = now;
            now = tem;
        }
        //返回新链表头指针
        return pre;
    }
}
```
![双指针.png](https://pic.leetcode-cn.com/f552fcfce31789986d652feabf1054a77c8fde808965db04d4f9dde077f72544-%E5%8F%8C%E6%8C%87%E9%92%88.png)
