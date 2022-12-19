### 解题思路
递归实现

### 代码

```ruby
def reverse_list(head)
    if head == nil or head.next == nil
        return head
    end
    new_head = reverse_list(head.next)
    head.next.next = head
    head.next = nil
    return new_head
end
```