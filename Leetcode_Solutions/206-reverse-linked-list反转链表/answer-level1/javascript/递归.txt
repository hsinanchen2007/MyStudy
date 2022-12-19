### 解题思路
简单的递归，注意递归的时候用head.next定位后部分的尾巴，然后把head再接上去（一定要接head，不然下一次不能定位了）

```
var reverseList = function(head) {
    if(head == null || head.next == null)  return head;
    let newReverseList = reverseList(head.next);
    let newReverseListTail = head.next;
    head.next = null
    newReverseListTail.next = head;
    head.next = null
    return newReverseList;
};

```


