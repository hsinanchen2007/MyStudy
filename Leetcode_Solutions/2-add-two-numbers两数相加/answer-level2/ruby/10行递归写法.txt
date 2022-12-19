脚本语言就是要简单，直观。
另外这个其实可以优化成尾递归。
JavaScript
```
var addTwoNumbers = function(l1, l2, c=false) {
  if (l1 === null && l2 === null) {
    return c ? new ListNode(1) : null;
  }
  const [a, la] = l1 === null ? [0, null] : [l1.val, l1.next];
  const [b, lb] = l2 === null ? [0, null] : [l2.val, l2.next];
  const x = a + b + (c ? 1 : 0)
  const l = new ListNode(x % 10);
  l.next = addTwoNumbers(la, lb, x >= 10);
  return l;
};
```
Ruby 真的是能少写一个字绝不多写一个字
Ruby
```
def add_two_numbers(l1, l2, c=false)
  if l1 == nil && l2 == nil then return c ? ListNode.new(1) : nil end
  a, la = l1 == nil ? [0, nil] : [l1.val, l1.next]
  b, lb = l2 == nil ? [0, nil] : [l2.val, l2.next]
  x = a + b + (c ? 1 : 0)
  l = ListNode.new(x % 10)
  l.next = add_two_numbers(la, lb, x >= 10)
  return l
end
```
