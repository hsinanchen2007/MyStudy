```ruby []
def add_two_numbers(l1, l2)
    head = ListNode.new(0)
    curr = head
    carry = 0
    while l1 || l2
        n1 = l1 ? l1.val : 0
        n2 = l2 ? l2.val : 0
        n = carry+n1+n2
        carry = n/10
        tmp_list = ListNode.new(n%10)
        curr.next = tmp_list
        curr = tmp_list

        l1 = l1.next if l1
        l2 = l2.next if l2
    end
    if carry>0
        curr.next = ListNode.new(carry)
    end
    return head.next
    
end
```
