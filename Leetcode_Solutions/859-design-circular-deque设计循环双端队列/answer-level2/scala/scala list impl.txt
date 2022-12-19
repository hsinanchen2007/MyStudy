```scala []
// a3::a2::a1::a0::Nil
// rear         front
class MyCircularDeque(_k: Int) {
    val k = _k
    var l = List.empty[Int]
    def insertFront(x: Int): Boolean = if(l.length == k) false else {
        l = l :+ x
        true
    }
    def insertLast(x: Int): Boolean = if(l.length == k) false else {
        l ::= x
        true
    }
    def deleteFront(): Boolean = l match {
        case Nil => false
        case _ => l = l.dropRight(1); true
    }
    def deleteLast(): Boolean = l match {
        case Nil => false
        case h::t => l =t; true
    }
    def getFront(): Int = if(l.nonEmpty) l.last else -1
    def getRear(): Int = l.headOption.getOrElse(-1)
    def isEmpty(): Boolean = l.isEmpty
    def isFull(): Boolean = l.length == k
}
```
