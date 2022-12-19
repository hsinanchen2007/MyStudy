> 思路: 先构建结果的数组，在将数组转成链表
```
var addTwoNumbers = function(l1, l2) {
    // 生成结果数组
    const arr = []
    let addOne = 0
    while(l1 || l2 || addOne) {
        let sum = (l1 ? l1.val : 0) + (l2 ? l2.val : 0) + addOne
        addOne = 0
        if(sum >= 10) {
            addOne = 1 
            sum %= 10
        }
        arr.push(sum)
        l1 = l1 ? l1.next : null
        l2 = l2 ? l2.next : null
    }
    // 用数组构建链表
    const head = new ListNode(arr[0])
    let pnode = head
    for (let i = 1; i < arr.length; i++) {
      let node = new ListNode(arr[i])
      pnode.next = node
      pnode = node
    }
    return head
};
```
