```ruby
object Solution {
    def addTwoNumbers(l1: ListNode, l2: ListNode): ListNode = {
        toListNode(addList(toList(l1).reverse, toList(l2).reverse, 0))
    }
    
    def toList(l:ListNode, acc:List[Int] = Nil):List[Int] = l match {
        case null => acc
        case _ => toList(l.next, l.x::acc)
    }
    def toListNode(l:List[Int], acc:ListNode = null):ListNode = l match {
        case Nil => acc
        case h::t => 
        val node = new ListNode(h)
        node.next = acc
        toListNode(t, node)
    }
    
    def addList(l1:List[Int],l2:List[Int], carry:Int, acc:List[Int] = Nil):List[Int] = (l1,l2) match {
        case (Nil, Nil) => if(carry != 0) carry::acc else acc
        case (Nil, h::t)=> addList(Nil, t, (h + carry) / 10, (h + carry) % 10 ::acc)
        case (h::t, Nil)=> addList(Nil, t, (h + carry) / 10, (h + carry) % 10 ::acc)
        case (h::t,h2::t2) => addList(t, t2, (h + h2 + carry) / 10, (h + h2 + carry) % 10 ::acc)
    }
}
```
