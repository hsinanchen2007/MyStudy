```
var addTwoNumbers = function (l1, l2) {
  let rl = new ListNode('head')
  let tl = rl
  let tempSum,carry = 0
  while (l1 || l2 || carry) {
    tempSum = ((l1 && l1.val) || 0) + ((l2 && l2.val) || 0) + carry
    tl.next = new ListNode(tempSum % 10)
    carry = tempSum >= 10 ? 1 : 0
    l1 = l1&&l1.next || null
    l2 = l2&&l2.next || null
    tl = tl.next
  }
  return rl.next
}
//附带一个生成由数组生成用例的
function createTest(list) {
  let rl = new ListNode(list[0]),
    templ = rl
  for (let i = 1, l = list.length; i < l; i++) {
    templ.next = new ListNode(list[i])
    templ = templ.next
  }
  return rl
}
```

