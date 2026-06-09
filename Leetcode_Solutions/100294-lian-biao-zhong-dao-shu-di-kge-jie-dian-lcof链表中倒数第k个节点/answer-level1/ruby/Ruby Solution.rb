### 解题思路
用栈存储链表节点，遍历一遍后，返回倒数第k个元素

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
# @param {Integer} k
# @return {ListNode}
def get_kth_from_end(head, k)
    stack = []
    while head != nil
        stack += [head]
        head = head.next
    end    
    stack[-k]  
end
```