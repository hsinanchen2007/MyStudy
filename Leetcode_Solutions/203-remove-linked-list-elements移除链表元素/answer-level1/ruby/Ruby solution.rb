ruby solution
```ruby
def remove_elements(head, val)
    if head == nil  # case: [] 1
        return head
    end
    while head != nil && head.val == val  # case [1] 1
        head = head.next
    end
    node = head
    while node != nil && node.next != nil # other cases
        if node.next.val == val
            node.next = node.next.next
        else
            node = node.next
        end
    end
    return head
end
```
