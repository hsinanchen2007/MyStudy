```
public static ListNode sortList(ListNode head) {
    /*定义当前指针*/
    ListNode cur = head;
    /*链表数量*/
    int count = 0;
    ListNode countNode = head;
    /*计算链表数量*/
    while (countNode != null) {
      count++;
      countNode = countNode.next;
    }
    /*计算新的链表数量*/
    int length = count / 2 + count % 2;
    ListNode[] nodes = new ListNode[length];
    int co = 0;
    /*把链表2个节点排序形成新的链表放入一个链表数组中*/
    while (cur != null && cur.next != null) {
      ListNode tmp = cur.next;
      ListNode tmp1 = cur;
      ListNode tmp2 = cur.next.next;
      tmp.next = null;
      tmp1.next = null;
      if (tmp1.val > tmp.val) {
        tmp.next = tmp1;
        nodes[co] = tmp;
      } else {
        tmp1.next = tmp;
        nodes[co] = tmp1;
      }
      co++;
      cur = tmp2;
    }
    /*防止奇数个时元素没放入*/
    if (cur != null) {
      nodes[length - 1] = cur;
    }
    /*合并*/
    return mergeList(nodes);
  }

  public static ListNode mergeList(ListNode[] lists) {
    /*计算新的数组大小*/
    int count = lists.length / 2 + lists.length % 2;
    /*如果数组里的元素为0返回null*/
    if (count == 0) {
      return null;
    }
    /*链表两两合并后放入新的链表数组中*/
    ListNode[] newLists = new ListNode[count];
    for (int i = 0; i < lists.length; i = i + 2) {
      if (lists.length <= i + 1) {
        newLists[count - 1] = lists[i];
        break;
      }
      newLists[i / 2] = merge(lists[i], lists[i + 1]);
    }
    /*如果新链表数组的元素大于1递归调用*/
    if (newLists.length > 1) {
      return mergeList(newLists);
    }
    /*返回结果*/
    return newLists.length == 0 ? null : newLists[0];
  }

  /**
   * 合并2个有序链表
   *
   * @param l1
   * @param l2
   * @return
   */
  public static ListNode merge(ListNode l1, ListNode l2) {
    /*定义一个哑节点*/
    ListNode dumb = new ListNode(0);
    /*定义一个节点赋值为哑节点*/
    ListNode head = dumb;
    /*当2个链表都不为空时继续遍历*/
    while (l1 != null && l2 != null) {
      /*如果l1的值小于l2的值，则dumb的下一个指向l1，l1移向自己的下一位*/
      if (l1.val < l2.val) {
        dumb.next = l1;
        l1 = l1.next;
      } else {
        /*如果l1的值大于l2的值，则dumb的下一个指向l2，l2移向自己的下一位*/
        dumb.next = l2;
        l2 = l2.next;
      }
      /*哑节点移向自己的下一位*/
      dumb = dumb.next;
    }
    /*防止l1和l2肯定有一个不为null，所以需要拼接没遍历完的*/
    dumb.next = (l1 == null ? l2 : l1);
    return head.next;
  }
```
