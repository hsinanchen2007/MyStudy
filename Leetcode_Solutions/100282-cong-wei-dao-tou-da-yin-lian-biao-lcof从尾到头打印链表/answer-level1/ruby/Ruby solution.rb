get all the values and return the reversed array.
```ruby
def reverse_print(head)
    res = []
    while head != nil
        res += [head.val]
        head = head.next
    end
    res.reverse
end
```
