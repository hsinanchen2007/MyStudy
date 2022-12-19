```scala
import scala.collection.mutable

class MyStack() {

    /** Initialize your data structure here. */

  var q1: mutable.Queue[Int] = mutable.Queue[Int]()
  var q2: mutable.Queue[Int] = mutable.Queue[Int]()

  /** Push element x onto stack. */
  def push(x: Int): Unit = {
    q1.enqueue(x)
  }

  /** Removes the element on top of the stack and returns that element. */
  def pop(): Int = {
    val res = top()
    q1.dequeue()
    res
  }

  /** Get the top element. */
  def top(): Int = {
    if (empty()) throw new Error("stack is empty")
    if (q1.isEmpty) {
      val t = Tuple2(q1, q2)
      val tmp = t.swap
      q1 = tmp._1
      q2 = tmp._2
    }
    while (q1.length > 1) {
      q2.enqueue(q1.front)
      q1.dequeue()
    }
    q1.front
  }

  /** Returns whether the stack is empty. */
  def empty(): Boolean = {
    q1.isEmpty && q2.isEmpty
  }

}

/**
 * Your MyStack object will be instantiated and called as such:
 * var obj = new MyStack()
 * obj.push(x)
 * var param_2 = obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.empty()
 */
```