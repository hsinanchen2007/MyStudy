给出两个 `非空` 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 `逆序` 的方式存储的，并且它们的每个节点只能存储 `一位` 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 `0` 之外，这两个数都不会以 `0` 开头。

### 示例：

```markdown
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
```

### 参考代码：

```cs
/// <summary>
/// 返回链表中逆序存储的两数之和
/// </summary>
/// <param name="l1"> 非空链表，逆序表示数值 1 </param>
/// <param name="l2"> 非空链表，逆序表示数值 2 </param>
/// <returns> 非空链表，逆序表示数值之和 </returns>
public ListNode AddTwoNumbers(ListNode l1, ListNode l2)
{
    var listNode = new ListNode(-1);
    var lnTemp = listNode;
    int temp = 0;

    while (l1 != null || l2 != null || temp / 10 != 0)
    {
        temp = (l1?.val ?? 0) + (l2?.val ?? 0) + temp / 10;
        lnTemp.next = lnTemp.next ?? new ListNode(-1);
        lnTemp.next.val = temp % 10;
        lnTemp = lnTemp.next;
        l1 = l1?.next; l2 = l2?.next;
    }
    return listNode.next;
}
```