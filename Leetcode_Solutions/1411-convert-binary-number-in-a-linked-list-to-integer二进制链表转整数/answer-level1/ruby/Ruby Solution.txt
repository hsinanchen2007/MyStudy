ruby solution
```ruby
def get_decimal_value(head)
    n = 0
    while head != nil  
        n *= 2  # left shift the original n
        n += head.val  # add the current bit
        head = head.next
    end
    n
end
```
