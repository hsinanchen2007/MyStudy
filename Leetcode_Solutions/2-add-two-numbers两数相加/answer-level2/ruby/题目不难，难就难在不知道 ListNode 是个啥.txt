### 解题思路
先摸清楚 ListNode 是啥
```
puts l1
puts l1.val
puts l1.next
puts l1.next.val
```
l1，l2 变数组后，反转数组变成整数 `a1.reverse.join().to_i`，相加后再反转，注意最后的结果需要数字数组。

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

# @param {ListNode} l1
# @param {ListNode} l2
# @return {ListNode}
def add_two_numbers(l1, l2)
  a1 = list_node_to_array(l1)
  a2 = list_node_to_array(l2)
  r = ListNode.new
  (a1.reverse.join().to_i + a2.reverse.join().to_i).to_s.chars.reverse.map(&:to_i)
end

def list_node_to_array(list_node)
  _r = []
  loop do
    _r << list_node.val
    list_node = list_node.next
    break unless list_node
  end
  _r
end
```