```javascript []
console.log('Hello world!')
```
```python []
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        temp = head
        while temp and temp.next:
            if temp.val == temp.next.val:
                temp.next = temp.next.next
            else:
                temp = temp.next
        return head
```
```ruby []
puts 'Hello world!'
```
