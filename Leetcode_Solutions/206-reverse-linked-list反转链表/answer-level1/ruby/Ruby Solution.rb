### 解题思路
迭代翻转

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
# @return {ListNode}
def reverse_list(head)
    if head == nil or head.next == nil
       return head 
    end
    new_head = reverse_list(head.next)
    head.next.next = head
    head.next = nil
    new_head
end
```