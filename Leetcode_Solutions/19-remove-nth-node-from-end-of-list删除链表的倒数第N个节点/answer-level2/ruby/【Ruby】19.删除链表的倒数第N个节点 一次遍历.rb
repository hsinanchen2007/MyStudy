### 解题思路
参考官方题解

### 代码

```ruby
# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

# @param {ListNode} head
# @param {Integer} n
# @return {ListNode}
def remove_nth_from_end(head, n)
  dummy = ListNode.new(0)
  dummy.next = head
  first = dummy
  second = dummy
  for i in (1..n) do
    first = first.next
  end

  while first.next != nil
    first = first.next
    second = second.next
  end

  second.next = second.next.next
  dummy.next
end
```