```
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {

	slice1 := make([]int, 0, 1)
	slice2 := make([]int, 0, 1)
	tmp := l1
	for tmp != nil {
		slice1 = append(slice1, tmp.Val)
		tmp = tmp.Next
	}
	tmp = l2
	for tmp != nil {
		slice2 = append(slice2, tmp.Val)
		tmp = tmp.Next
	}
	reverse(slice1)
	reverse(slice2)
	sum := add(slice1, slice2)
	head := &ListNode{}
	pos := head
	for count := 0; count < len(sum); count++ {
		node := &ListNode{sum[count], nil}
		pos.Next = node
		pos = node
	}
	return head.Next
}

func reverse(data []int) []int {

	for left, right := 0, len(data)-1; left < right; left, right = left+1, right-1 {
		data[left], data[right] = data[right], data[left]
	}
	return data
}

func add(a []int, b []int) []int {

	lenA := len(a)
	lenB := len(b)
	var lenShort = lenB
	var lenLong = lenA
	var short = b
	var long = a
	if lenA < lenB {
		lenShort = lenA
		lenLong = lenB
		long = b
		short = a
	}
	var lenDiff = lenLong - lenShort
	var carry = 0
	var mod = 0
	sum := make([]int, 0, 1)
	for count := lenShort; count > 0; count-- {
		tmpShort := short[count-1]
		tmpLong := long[lenDiff+count-1]
		tmpSum := tmpShort + tmpLong + carry
		carry = tmpSum / 10
		mod = tmpSum % 10
		sum = append(sum, mod)
	}
	for count := lenDiff; count > 0; count-- {
		tmp := long[count - 1] + carry
		carry = tmp / 10
		mod = tmp % 10
		sum = append(sum, mod)
	}
	if carry != 0 {
		sum = append(sum, carry)
	}
	return sum
}
```