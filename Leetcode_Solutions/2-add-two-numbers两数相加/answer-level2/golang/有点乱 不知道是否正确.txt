```
type LinkNode struct {
	val int
	next *LinkNode
}

type Linker interface {
	Add(head * LinkNode, value int)
	Print(head * LinkNode)
}

func Add(head * LinkNode, value int)  {
	point := head
	for(point.next != nil) {
		point = point.next
	}
	newNode := &LinkNode{value,nil}
	point.next = newNode
}

func Print(head * LinkNode){
	point := head
	str := ""
	for(point != nil) {
		str = str + strconv.Itoa(point.val)+"->"
		point = point.next
	}
	fmt.Println(str)
}

func addTowLink(link1 *LinkNode, link2 *LinkNode)(newNode *LinkNode){
	newNode = &LinkNode{}
	var point = newNode
	var carry = 0
	var n = point
	for (link1 != nil || link2 != nil)  {
		if link1 == nil {
			if link2.val + carry >= 10 {
				n.val = (link2.val + carry) - 10
				carry = 1
				point.next = n
				point = n
			} else {
				link2.val = link2.val + carry
				point.next = link2
				point = link2
				break
			}
			link2 = link2.next
		} else if link2 == nil {
			if link1.val + carry >= 10 {
				n.val = (link1.val + carry) - 10
				carry = 1
				point.next = n
				point = n
			} else {
				link1.val = link1.val + carry
				point.next = link1
				point = link1
				break
			}
			link1 = link1.next
		} else {
			count := link1.val + link2.val + carry
			if count >= 10{
				n.val = count - 10
				carry = 1
			} else {
				n.val = count
				carry = 0
			}
			point.next = n
			point = n
			link1 = link1.next
			link2 = link2.next
		}
		if carry == 1 {
			var n = &LinkNode{1,nil}
			point.next = n
		}
		n = &LinkNode{}
	}
	return
}

func main() {
	link1 := &LinkNode{0,nil}
	link2 := &LinkNode{5,nil}
	Add(link1,3)
	Add(link2,9)
	Add(link2,9)
	Print(link1)
	Print(link2)
	newNode := addTowLink(link1,link2)
	Print(newNode)
}
```
