ruby solution
```ruby
def delete_node(head, val)
    if head.val == val
        return head.next
    else
        node = head
        while node.next != nil
            if node.next != nil && node.next.val == val 
                node.next = node.next.next
                return head
            else
                node = node.next
            end
        end
        return head
    end
end
```
