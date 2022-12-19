```scala []
class MyCircularQueue(_k: Int) {
    val k = _k
    var l = List.empty[Int]
    def enQueue(x: Int): Boolean = 
    if(l.length == k)  false else {
        l = x::l
        true 
    } 
    def deQueue(): Boolean = l match {
        case Nil => false
        case _ => 
            l = l.dropRight(1)
            true
    }
    def Rear(): Int = l match {
        case Nil => -1
        case h::t => h
    }
    def Front(): Int = l match {
        case Nil => -1
        case _ => l.last
    }
    def isEmpty(): Boolean = l.isEmpty
    def isFull():  Boolean = l.length == k
}
```