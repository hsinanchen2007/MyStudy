 var removeNthFromEnd = function(head, n) {
        let current = head
        let count = 0
        while (current) {
          count++
          current = current.next
        }
        count = count - n
        head = { val: '哨兵', next: head }
        current = head
        while (count != 0) {
          current = current.next
          count--
        }
        current.next = current.next.next
        return head.next
      }