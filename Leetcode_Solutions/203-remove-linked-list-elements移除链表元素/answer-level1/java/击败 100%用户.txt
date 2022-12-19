![WX20191107-002424@2x.png](https://pic.leetcode-cn.com/298fb84f6c9e7a4b58e4611ab0d071ad75358a868a6dc80a1e326685cc152781-WX20191107-002424@2x.png)

```
public static ListNode removeElements(ListNode head, int val) {
    /*定义一个哑节点*/
    ListNode dumb = new ListNode(0);
    /*定义一个节点赋值为哑节点*/
    dumb.next = head;
    /*定义一个遍历节点*/
    ListNode iter = dumb;
    /*当下个节点不为null时继续遍历*/
    while (iter.next != null) {
      ListNode curr = iter.next;
      /*如果下个节点等于val值，则下个节点替换为下下个节点并立即进行下次迭代*/
      if (curr.val == val) {
        iter.next = curr.next;
        continue;
      }
      /*如果不相等，迭代节点向后移动一个*/
      iter = iter.next;
    }
    return dumb.next;
  }
```
