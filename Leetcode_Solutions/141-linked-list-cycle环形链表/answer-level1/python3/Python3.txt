```
def hasCycle(head):
	if not head:
		return False
	f, s = head, head
	while s.next and s.next.next:
		f = f.next
		s = s.next.next
		if f == s:
			return True
	return False
```
